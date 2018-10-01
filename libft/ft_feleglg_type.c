/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_feleglg_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/26 20:28:41 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;

	if (!(tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0])))
		return (NULL);
	if (ft_minus_format(comm))
		ft_strncpy(tmp, variab, ft_strlen(variab));
	else
		ft_strcpy(tmp + siz_cuant[0] - ft_strlen(variab), variab);
	if (comm[ft_strlen(comm) - 1] == 'E' || comm[ft_strlen(comm) - 1] == 'G')
		*(ft_strchr(tmp, 'e')) = 'E';
	ft_strdel(&variab);
	ft_strdel(&comm);
	return (tmp);
}

static char	*check_formats(char *comm, char *variable, int *siz_cuant)
{
	if (!(variable = ft_hash_format(comm, variable, siz_cuant)))
		return (NULL);
	if (!(variable = ft_apostrophe_format(comm, variable, siz_cuant)))
		return (NULL);
	if (!(variable = ft_zero_format(comm, variable, siz_cuant)))
		return (NULL);
	if (!(variable = ft_space_format(comm, variable, siz_cuant)))
		return (NULL);
	if (!(variable = ft_plus_format(comm, variable, siz_cuant)))
		return (NULL);
	return (variable);
}

static int	check_nan_inf(int *siz_cuant, char *variable, char *comm)
{
	if (!(ft_isdigit(*(variable + 1))))
	{
		siz_cuant[1] = ft_strlen(variable);
		if (siz_cuant[0] < siz_cuant[1])
			siz_cuant[0] = siz_cuant[1];
		return (0);
	}
	ft_ajust_params(siz_cuant, variable, comm);
	return (1);
}

int			ft_feleglg_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, &comm, ap);
	if (siz_cuant[0] == -2 || siz_cuant[1] == -2)
		return (-1);
	if (!(variable = g_mod_selector[0](ap[0], ap[1], comm)))
		return (-1);
	if (check_nan_inf(siz_cuant, variable, comm))
	{
		if (!(variable = ft_round(variable, siz_cuant[1], comm)))
			return (-1);
		if (!(variable = ft_putthepoint(variable, siz_cuant, comm)))
			return (-1);
		if (!(variable = check_formats(comm, variable, siz_cuant)))
			return (-1);
	}
	if (!(variable = writer(siz_cuant, comm, variable)))
		return (-1);
	if (!(*res = ft_memjoinfree(*res, variable, len, siz_cuant[0])))
		return (-1);
	return (len + siz_cuant[0]);
}

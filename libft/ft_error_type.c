/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:04:44 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/23 01:20:45 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;

	if (ft_search_zero_format(comm) && !ft_minus_format(comm))
	{
		if (!(tmp = ft_memset(ft_strnew(siz_cuant[0]), '0', siz_cuant[0])))
			return (NULL);
	}
	else
	{
		if (!(tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0])))
			return (NULL);
	}
	if (ft_minus_format(comm))
		tmp = ft_strncpy(tmp, variab, 1);
	else
		ft_strncpy(tmp + siz_cuant[0] - 1, variab, 1);
	ft_strdel(&comm);
	ft_strdel(&variab);
	return (tmp);
}

int				ft_error_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	comm = ft_strjoinfree(ft_strdup("%"), comm);
	if (ft_findend(comm) < 0 && ft_strlen(comm) > 1)
		return (len);
	ft_field_format(siz_cuant, &comm, ap);
	if (siz_cuant[1] == -2 || siz_cuant[0] == -2)
		return (-1);
	if (!(variable = ft_strdup(comm + ft_strlen(comm) - 1)))
		return (-1);
	if (!siz_cuant[0])
		siz_cuant[0] = 1;
	if (!(variable = writer(siz_cuant, comm, variable)))
		return (-1);
	if (!(*res = ft_memjoinfree(*res, variable, len, siz_cuant[0])))
		return (-1);
	return (len + siz_cuant[0]);
}

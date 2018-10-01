/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:52:18 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/17 00:47:20 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*writer(int *siz_cuant, char *comm, char *variab)
{
	char	*tmp;
	int		len;

	len = ft_strlen(variab);
	if (!(tmp = ft_memset(ft_strnew(siz_cuant[0]), ' ', siz_cuant[0])))
		return (NULL);
	if (ft_minus_format(comm))
		ft_strncpy(tmp, variab, len);
	else
		ft_strcpy(tmp + siz_cuant[0] - len, variab);
	ft_strdel(&variab);
	ft_strdel(&comm);
	return (tmp);
}

int			ft_p_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		siz_cuant[2];
	char	*variable;

	ft_field_format(siz_cuant, &comm, ap);
	variable = (char *)ft_locate_pointer(comm, ap[0], ap[1]);
	if (!(variable = ft_dectohex(&variable, sizeof(void *), comm)))
		return (-1);
	if (!(variable = ft_zero_format(comm, variable, siz_cuant)))
		return (-1);
	if (!(variable = ft_hash_format("#x", variable, siz_cuant)))
		return (-1);
	if (!ft_strcmp(variable, "0x0") && !siz_cuant[1])
	{
		ft_strdel(&variable);
		variable = ft_strdup("0x");
		siz_cuant[0]--;
	}
	ft_ajust_params(siz_cuant, variable, comm);
	if (!(variable = writer(siz_cuant, comm, variable)))
		return (-1);
	if (!(*res = ft_memjoinfree(*res, variable, len, siz_cuant[0])))
		return (-1);
	return (len + siz_cuant[0]);
}

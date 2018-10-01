/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 23:14:04 by jagarcia          #+#    #+#             */
/*   Updated: 2018/03/14 15:52:16 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*non_printable(char *variable)
{
	int		i;
	char	*new_variable;
	int		size;
	int		len;

	len = ft_strlen(variable);
	i = 0;
	size = 0;
	while (i < len + 1)
		size += ft_strlen(g_symbols[(int)(variable[i++])]);
	if (!(new_variable = ft_strnew(size)))
		return (NULL);
	i = 0;
	while (i < len + 1)
		ft_strcat(new_variable, g_symbols[(int)variable[i++]]);
	return (new_variable);
}

int				ft_r_type(char *comm, va_list *ap, char **res, size_t len)
{
	int		len_var;
	char	*variable;

	if (!(variable = (char *)ft_locate_pointer(comm, ap[0], ap[1])))
		return (-1);
	if (!(variable = non_printable(variable)))
		return (-1);
	len_var = ft_strlen(variable);
	if (!(*res = ft_memjoinfree(*res, variable, len, len_var)))
		return (-1);
	return (len + len_var);
}

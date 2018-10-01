/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:12:39 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/22 18:57:46 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*write_zeros(char *variable, int zero_cuant)
{
	char	*new_variab;
	int		neg;

	if (zero_cuant < 0)
		return (variable);
	neg = 0;
	if (!zero_cuant)
		return (variable);
	if (!(new_variab = ft_strnew(ft_strlen(variable) + zero_cuant)))
		return (NULL);
	if (*variable == '-')
	{
		neg = 1;
		*new_variab = '-';
	}
	ft_memset(new_variab + neg, '0', zero_cuant);
	ft_strcat(new_variab, variable + neg);
	ft_strdel(&variable);
	return (new_variab);
}

char		*ft_zero_format(char *comm, char *variable, int *siz_cuant)
{
	int neg;
	int t;

	t = ft_toupper(comm[ft_strlen(comm) - 1]);
	neg = 0;
	if (*variable == '-')
		neg = 1;
	if (t == 'F' || t == 'G' || t == 'E')
	{
		if (ft_search_zero_format(comm))
			return (write_zeros(variable,
						siz_cuant[0] + neg - ft_strlen(variable)));
			return (variable);
	}
	if (siz_cuant[1] == -1)
	{
		if (ft_search_zero_format(comm) && !ft_minus_format(comm))
			return (write_zeros(variable, siz_cuant[0] - ft_strlen(variable)));
		else
			return (variable);
	}
	return (write_zeros(variable, siz_cuant[1] - ft_strlen(variable) + neg));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_z_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:33:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/21 15:25:34 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ltoa(char *comm, va_list ap, va_list ap2)
{
	void	*aux;
	char	*variable;

	aux = ft_locate_date(comm, 14, ap, ap2);
	variable = ft_ltoa_base(*((size_t *)aux), 10);
	ft_memdel(&aux);
	return (variable);
}

static char		*ultoa(char *comm, va_list ap, va_list ap2)
{
	void	*aux;
	char	*variable;

	aux = ft_locate_date(comm, 14, ap, ap2);
	variable = ft_ultoa_base(*((size_t *)aux), 10);
	ft_memdel(&aux);
	return (variable);
}

char			*ft_z_mod(va_list ap, va_list ap2, char *comm)
{
	char	comand;

	comand = comm[ft_strlen(comm) - 1];
	if ((comand == 'd') || (comand == 'i'))
		return (ltoa(comm, ap, ap2));
	if (comand == 'u')
		return (ultoa(comm, ap, ap2));
	if (comand == 'o')
		return (ft_dectooct(ft_locate_date(comm, 14, ap, ap2), sizeof(size_t)));
	if ((comand == 'x') || (comand == 'X'))
	{
		return (ft_dectohex(ft_locate_date(comm, 14, ap, ap2),
					sizeof(size_t), comm));
	}
	if (comand == 'b')
		return (ft_dectobin(ft_locate_date(comm, 14, ap, ap2), sizeof(size_t)));
	return (NULL);
}

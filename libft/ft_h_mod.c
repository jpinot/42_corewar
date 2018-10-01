/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:33:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/12 15:48:19 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ltoa(char *comm, va_list ap, va_list ap2)
{
	void *aux;
	char *variable;

	aux = ft_locate_date(comm, 3, ap, ap2);
	variable = ft_ltoa_base(*((short *)aux), 10);
	ft_memdel(&aux);
	return (variable);
}

static char	*ultoa(char *comm, va_list ap, va_list ap2)
{
	void *aux;
	char *variable;

	aux = ft_locate_date(comm, 4, ap, ap2);
	variable = ft_ultoa_base(*((unsigned short *)aux), 10);
	ft_memdel(&aux);
	return (variable);
}

char		*ft_h_mod(va_list ap, va_list ap2, char *comm)
{
	char comand;

	comand = comm[ft_strlen(comm) - 1];
	if ((comand == 'd') || (comand == 'i'))
		return (ltoa(comm, ap, ap2));
	if (comand == 'u')
		return (ultoa(comm, ap, ap2));
	if (comand == 'o')
	{
		return (ft_dectooct(ft_locate_date(comm, 4, ap, ap2),
					sizeof(unsigned short)));
	}
	if ((comand == 'x') || (comand == 'X'))
	{
		return (ft_dectohex(ft_locate_date(comm, 4, ap, ap2),
					sizeof(unsigned short), comm));
	}
	if (comand == 'b')
	{
		return (ft_dectobin(ft_locate_date(comm, 4, ap, ap2),
					sizeof(unsigned short)));
	}
	return (NULL);
}

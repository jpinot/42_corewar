/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_none_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 01:33:10 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/17 03:52:34 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ltoa(char *comm, va_list ap, va_list ap2)
{
	void *aux;
	char *variable;

	aux = ft_locate_date(comm, 5, ap, ap2);
	variable = ft_ltoa_base(*((int *)aux), 10);
	ft_memdel(&aux);
	return (variable);
}

static char	*ultoa(char *comm, va_list ap, va_list ap2)
{
	void *aux;
	char *variable;

	aux = ft_locate_date(comm, 6, ap, ap2);
	variable = ft_ultoa_base(*((unsigned int *)aux), 10);
	ft_memdel(&aux);
	return (variable);
}

char		*ft_none_mod(va_list ap, va_list ap2, char *comm)
{
	char comand;

	comand = ft_toupper(comm[ft_strlen(comm) - 1]);
	if ((comand == 'D') || (comand == 'I'))
		return (ltoa(comm, ap, ap2));
	if (comand == 'U')
		return (ultoa(comm, ap, ap2));
	if (comand == 'O')
	{
		return (ft_dectooct(ft_locate_date(comm, 6, ap, ap2),
				sizeof(unsigned int)));
	}
	if (comand == 'X')
	{
		return (ft_dectohex(ft_locate_date(comm, 6, ap, ap2),
				sizeof(unsigned int), comm));
	}
	if (comand == 'B')
		return (ft_dectobin(ft_locate_date(comm, 5, ap, ap2), sizeof(int)));
	if (comand == 'F' || comand == 'G' || comand == 'E')
		return (ft_grisu((double *)ft_locate_date(comm, 15, ap, ap2)));
	return (NULL);
}

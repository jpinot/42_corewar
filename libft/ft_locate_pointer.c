/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locate_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:32:01 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/07 23:33:00 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	*exec_dolar(char *comm, va_list ap)
{
	va_list	ap3;
	int		loc;
	void	*variable;

	va_copy(ap3, ap);
	loc = ft_atoi(comm);
	while (loc > 1)
	{
		va_arg(ap3, void *);
		loc--;
	}
	variable = va_arg(ap3, void *);
	va_end(ap3);
	return (variable);
}

void		*ft_locate_pointer(char *comm, va_list ap, va_list ap2)
{
	void	*variable;
	int		len;

	len = ft_strlen(comm) - 1;
	while (len >= 0)
	{
		if (comm[len] == '$')
		{
			while ((len - 1) >= 0 && ft_isdigit(comm[len - 1]))
				len--;
			if (comm[len - 1] != ',')
				return (exec_dolar(comm + len, ap));
		}
		len--;
	}
	variable = va_arg(ap2, void *);
	return (variable);
}

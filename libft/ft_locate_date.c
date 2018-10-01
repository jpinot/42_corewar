/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locate_date.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:32:01 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/07 21:32:15 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		size(int mem)
{
	if ((mem == 1) || (mem == 2))
		return (sizeof(signed char));
	else if ((mem == 3) || (mem == 4))
		return (sizeof(short));
	else if ((mem == 5) || (mem == 6))
		return (sizeof(int));
	else if (mem == 7)
		return (sizeof(wchar_t) * 2);
	else if ((mem == 8) || (mem == 9))
		return (sizeof(long));
	else if ((mem == 10) || (mem == 11))
		return (sizeof(long long));
	else if ((mem == 12) || (mem == 13))
		return (sizeof(intmax_t));
	else if (mem == 14)
		return (sizeof(size_t));
	return (0);
}

static void		*selector2(int mem, va_list ap, void *variable)
{
	if (mem == 8)
		*((long *)variable) = va_arg(ap, long);
	else if (mem == 9)
		*((unsigned long *)variable) = va_arg(ap, unsigned long);
	else if (mem == 10)
		*((long long *)variable) = va_arg(ap, long long);
	else if (mem == 11)
		*((unsigned long long *)variable) = va_arg(ap, unsigned long long);
	else if (mem == 12)
		*((intmax_t *)variable) = va_arg(ap, intmax_t);
	else if (mem == 13)
		*((uintmax_t *)variable) = va_arg(ap, uintmax_t);
	else if (mem == 14)
		*((size_t *)variable) = va_arg(ap, size_t);
	else if (mem == 15)
		*((double *)variable) = va_arg(ap, double);
	return (variable);
}

static void		*selector(int mem, va_list ap)
{
	void *variable;

	if (!(variable = ft_memalloc(size(mem))))
		return (NULL);
	if (mem > 7)
		return (selector2(mem, ap, variable));
	if (mem == 1)
		*((unsigned char *)variable) = va_arg(ap, int);
	else if (mem == 2)
		*((signed char *)variable) = va_arg(ap, int);
	else if (mem == 3)
		*((short *)variable) = va_arg(ap, int);
	else if (mem == 4)
		*((unsigned short *)variable) = va_arg(ap, int);
	else if (mem == 5)
		*((int *)variable) = va_arg(ap, int);
	else if (mem == 6)
		*((unsigned int *)variable) = va_arg(ap, unsigned int);
	else if (mem == 7)
		*((wchar_t *)variable) = va_arg(ap, wchar_t);
	return (variable);
}

static void		*exec_dolar(char *comm, int i, va_list ap, int mem)
{
	va_list		ap3;
	int			loc;
	void		*variable;

	va_copy(ap3, ap);
	if (ft_isdigit(comm[i]))
		loc = ft_atoi(comm);
	else
		loc = ft_atoi(comm + i + 1);
	while (loc > 1)
	{
		va_arg(ap3, void *);
		loc--;
	}
	variable = selector(mem, ap3);
	va_end(ap3);
	return (variable);
}

void			*ft_locate_date(char *comm, int mem, va_list ap, va_list ap2)
{
	void	*variable;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(comm);
	while (i < len)
	{
		if (comm[i] == '$')
		{
			i--;
			while (ft_isdigit(comm[i]) && i > 0)
				i--;
			return (exec_dolar(comm, i, ap, mem));
		}
		i++;
	}
	variable = selector(mem, ap2);
	return (variable);
}

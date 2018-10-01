/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:18:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/12 15:31:59 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		calcdigits(long val, int bas)
{
	int dig;

	dig = 1;
	while (val / bas)
	{
		val = val / bas;
		dig++;
	}
	return (dig);
}

static void		calcnum(char *res, long *value, int base)
{
	if (*value < (long)base)
		*res = *value;
	else
		*res = *value % base;
	if (*res >= 10)
		*res += -10 + 'A';
	else
		*res += '0';
	*value = *value / base;
}

static	char	*exception(void)
{
	char *str;

	str = ft_strnew(20);
	ft_strcpy(str, "-9223372036854775808");
	return (str);
}

char			*ft_ltoa_base(long value, int base)
{
	int		digits;
	int		neg;
	char	*res;

	neg = 0;
	if (value < 0)
	{
		if (value == -9223372036854775807 - 1)
			return (exception());
		value = -value;
		if (base == 10)
			neg = 1;
	}
	digits = calcdigits(value, base);
	if (!(res = ft_strnew(neg + digits + 1)))
		return (NULL);
	if (neg)
		res[0] = '-';
	neg = digits + neg - 1;
	while (digits--)
		calcnum(&(res[neg--]), &value, base);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:18:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/22 00:03:13 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calcdigits(int val, int bas)
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

static void		calcnum(char *res, int *value, int base)
{
	if (*value < base)
		*res = *value;
	else
		*res = *value % base;
	if (*res >= 10)
		*res += -10 + 'A';
	else
		*res += '0';
	*value = *value / base;
}

char			*ft_itoa_base(int value, int base)
{
	int		digits;
	int		neg;
	char	*res;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	neg = 0;
	if (value < 0)
	{
		if (value == -2147483648)
			return ("-2147483648");
		value = -value;
		if (base == 10)
			neg = 1;
	}
	digits = calcdigits(value, base);
	if (!(res = (char *)malloc(sizeof(char) * (neg + digits))))
		return (NULL);
	i = digits + neg - 1;
	if (neg)
		res[0] = '-';
	while (digits--)
		calcnum(&(res[i--]), &value, base);
	return (res);
}

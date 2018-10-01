/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:18:25 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/21 15:25:21 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		calcdigits(unsigned long val, long bas)
{
	long dig;

	dig = 1;
	while (val / bas)
	{
		val = val / bas;
		dig++;
	}
	return (dig);
}

static void		calcnum(char *res, unsigned long *value, int base)
{
	if (*value < (unsigned long)base)
		*res = *value;
	else
		*res = *value % base;
	if (*res >= 10)
		*res += -10 + 'a';
	else
		*res += '0';
	*value = *value / base;
}

char			*ft_ultoa_base(unsigned long value, int base)
{
	int		digits;
	char	*res;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	digits = calcdigits(value, base);
	if (!(res = ft_strnew(digits)))
		return (NULL);
	i = digits - 1;
	while (digits--)
		calcnum(&(res[i--]), &value, base);
	return (res);
}

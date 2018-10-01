/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 19:48:48 by jagarcia          #+#    #+#             */
/*   Updated: 2018/01/28 21:39:42 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_myfloat	ft_multiply(t_myfloat x, t_myfloat y)
{
	unsigned long int	ac;
	unsigned long int	bc;
	unsigned long int	ad;
	unsigned long int	bd;
	t_myfloat			r;

	ac = (x.mantissa >> 32) * (y.mantissa >> 32);
	bc = (x.mantissa & 0xFFFFFFFF) * (y.mantissa >> 32);
	ad = (x.mantissa >> 32) * (y.mantissa & 0xFFFFFFFF);
	bd = (x.mantissa & 0xFFFFFFFF) * (y.mantissa & 0xFFFFFFFF);
	r.mantissa = ac + (ad >> 32) + (bc >> 32) + ((((bd >> 32) +
	(ad & 0xFFFFFFFF) + (bc & 0xFFFFFFFF)) + (1U << 31)) >> 32);
	r.exponent = x.exponent + y.exponent + 64;
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_power.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:31:00 by jagarcia          #+#    #+#             */
/*   Updated: 2018/02/12 17:28:39 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_myfloat	ft_take_power(int k)
{
	t_myfloat	res;
	int			index;

	index = 343 + k;
	res.mantissa = g_powers_ten[index];
	res.exponent = g_powers_ten_e[index];
	return (res);
}

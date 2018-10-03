/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_getorders.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:35:19 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/03 19:48:14 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	invalid_token(int l)
{
	ft_putstr("\x1B[91mInvalid token at line ");
	ft_putnbr(l);
	ft_putstr("\n\e[0m");
}

void		ft_error_getorders(int l, int sel)
{
	l++;
	if (sel == 0)
		invalid_token(l);
	exit(-1);
}

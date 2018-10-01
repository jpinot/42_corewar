/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_par.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:37:49 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/18 18:51:21 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	invalid_par(int l, char *s, char *ex)
{
	ft_putstr("\x1B[91mInvalid parameter at line ");
	ft_putnbr(l);
	ft_putstr(":\n\t\x1B[92mUsage:\x1B[97m");
	ft_putstr("\n\t-Invalid format of parameter type ");
	ft_putstr(s);
	ft_putstr(".");
	ft_putstr("\n\t-Each parameter must be followed by a \"");
	ft_putchar(SEPARATOR_CHAR);
	ft_putstr("\".");
	ft_putstr("\n\t\x1B[92mExample:\x1B[97m\n\t");
	ft_putstr(ex);
}

void		ft_error_par(int l, int sel, char *s, char *ex)
{
	l++;
	if (sel == 0)
		invalid_par(l, s, ex);
	exit(-1);
}

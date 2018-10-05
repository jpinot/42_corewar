/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_par.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:37:49 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/05 15:24:17 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	invalid_par(int l, char *s, char *ex)
{
	ft_puterr("\x1B[91mInvalid parameter at line ");
	ft_putnerr(l);
	ft_puterr(":\n\t\x1B[92mUsage:\x1B[97m");
	ft_puterr("\n\t-Invalid format of parameter type ");
	ft_puterr(s);
	ft_puterr(".");
	ft_puterr("\n\t-Each parameter must be followed by a \"");
	ft_putchar(SEPARATOR_CHAR);
	ft_puterr("\".");
	ft_puterr("\n\t\x1B[92mExample:\x1B[97m\n\t");
	ft_puterr(ex);
}

void		ft_error_par(int l, int sel, char *s, char *ex)
{
	l++;
	if (sel == 0)
		invalid_par(l, s, ex);
	exit(-1);
}

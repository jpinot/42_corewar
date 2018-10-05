/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:37:37 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/05 15:24:14 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	invalid_inst(int l, char *s, char *ex)
{
	ft_puterr("\x1B[91mInvalid instruction at line ");
	ft_putnerr(l);
	ft_puterr(":\n\t\x1B[92mUsage:\x1B[97m");
	ft_puterr("\n\t-Each instruction must be in a unique line.");
	if (s)
	{
		ft_puterr("\n\t-Did you mena: \"");
		ft_puterr(s);
		ft_puterr("\"?\n");
	}
	ft_puterr("\n\t\x1B[92mExample:\x1B[97m\n\t");
	ft_puterr(ex);
}

static void	invalid_inst_line(int l)
{
	ft_puterr("\x1B[91mInvalid instruction at line ");
	ft_putnerr(l);
	ft_puterr(":\n\t\x1B[92mUsage:\x1B[97m");
	ft_puterr("\n\t-Each instruction must be in a unique line.");
	ft_puterr("\n\t-Each instruction must be separeted from the parameters.");
	ft_puterr("\n\t\x1B[92mExample:\x1B[97m\n\t");
	ft_puterr("sti r1, %32, %12");
}

static void	invalid_comm(int l)
{
	ft_puterr("\x1B[91mInvalid comment at line ");
	ft_putnerr(l);
	ft_puterr(":\n\t\x1B[92mUsage:\x1B[97m");
	ft_puterr("\n\t-Each comment must be at the end of the line.");
	ft_puterr("\n\t-Each comment must be preceded by \"");
	ft_putchar(COMMENT_CHAR);
	ft_puterr("\".");
	ft_puterr("\n\t\x1B[92mExample:\x1B[97m\n\t");
	ft_putchar(COMMENT_CHAR);
	ft_puterr("I'm a comment");
}

static void	no_parameter(int l)
{
	ft_puterr("\x1B[91mSyntax error at line ");
	ft_putnerr(l);
	ft_puterr(":\n\t\x1B[97m-No orders.");
}

void		ft_error_order(int l, int sel, char *s, char *ex)
{
	l++;
	if (sel == 0)
		invalid_inst(l, s, ex);
	if (sel == 1)
		invalid_comm(l);
	if (sel == 2)
		invalid_inst_line(l);
	if (sel == 3)
		no_parameter(l);
	exit(-1);
}

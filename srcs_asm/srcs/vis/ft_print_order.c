/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:35:56 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/30 21:57:07 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_put_type_2(int i)
{
	if (i == 9)
		ft_printf("\e[48;5;239m\e[38;5;40m%-10s\e[0m", "zjmp");
	if (i == 10)
		ft_printf("\e[48;5;239m\e[38;5;44m%-10s\e[0m", "ldi");
	if (i == 11)
		ft_printf("\e[48;5;239m\e[38;5;52m%-10s\e[0m", "sti");
	if (i == 12)
		ft_printf("\e[48;5;239m\e[38;5;58m%-10s\e[0m", "fork");
	if (i == 13)
		ft_printf("\e[48;5;239m\e[38;5;63m%-10s\e[0m", "lld");
	if (i == 14)
		ft_printf("\e[48;5;239m\e[38;5;72m%-10s\e[0m", "lldi");
	if (i == 15)
		ft_printf("\e[48;5;239m\e[38;5;88m%-10s\e[0m", "lfork");
	if (i == 16)
		ft_printf("\e[48;5;239m\e[38;5;94m%-10s\e[0m", "aff");
}

static void	ft_put_type_ord(int i)
{
	if (i == 1)
		ft_printf("\e[48;5;239m\e[38;5;6m%-10s\e[0m", "live");
	if (i == 2)
		ft_printf("\e[48;5;239m\e[38;5;11m%-10s\e[0m", "ld");
	if (i == 3)
		ft_printf("\e[48;5;239m\e[38;5;13m%-10s\e[0m", "st");
	if (i == 4)
		ft_printf("\e[48;5;239m\e[38;5;18m%-10s\e[0m", "add");
	if (i == 5)
		ft_printf("\e[48;5;239m\e[38;5;138m%-10s\e[0m", "sub");
	if (i == 6)
		ft_printf("\e[48;5;239m\e[38;5;111m%-10s\e[0m", "and");
	if (i == 7)
		ft_printf("\e[48;5;239m\e[38;5;32m%-10s\e[0m", "or");
	if (i == 8)
		ft_printf("\e[48;5;239m\e[38;5;38m%-10s\e[0m", "xor");
	if (i > 8)
		ft_put_type_2(i);
}

static void	ft_put_col(int sel, int pos, t_line *l)
{
	int i;
	int max;

	max = 19;
	i = -1;
	ft_printf("\e[38;5;%im", l->lab_color[pos]);
	if (sel == 2)
	{
		write(1, "%", 1);
		max = 18;
	}
	while (l->arg_lab[pos][++i] && l->arg_lab[pos][i] != SEPARATOR_CHAR
			&& l->arg_lab[pos][i] != ' ' && l->arg_lab[pos][i] != '\t'
			&& l->arg_lab[pos][i] != ';' && l->arg_lab[pos][i] != '#')
		write(1, &l->arg_lab[pos][i], 1);
	while (++i <= max)
		write(1, " ", 1);
	write(1, "\e[37m", 5);
}

static void	ft_put_par(int sel, int pos, t_line *l)
{
	if (sel == 1)
		ft_printf("r%-18i", l->arg[pos]);
	else if (sel == 2 && l->arg_lab[pos] == NULL)
		ft_printf("%%%-18i", l->arg[pos]);
	else if (sel == 2 && l->arg_lab[pos])
		ft_put_col(sel, pos, l);
	else if (sel == 3 && l->arg_lab[pos] == NULL)
		ft_printf("%-19i", l->arg[pos]);
	else if (sel == 3 && l->arg_lab[pos])
		ft_put_col(sel, pos, l);
}

void		ft_print_order(t_line *l)
{
	ft_printf("%-6i(%-2i) ->\t", l->pos, l->w);
	ft_put_type_ord(l->order_n);
	if (l->order_n != 1 && l->order_n != 9 && l->order_n != 12
			&& l->order_n != 15 && l->order_n != 16)
	{
		ft_put_par((l->ocp & 192) >> 6, 0, l);
		ft_put_par((l->ocp & 48) >> 4, 1, l);
		ft_put_par((l->ocp & 12) >> 2, 2, l);
	}
	else if (l->order_n == 9 || l->order_n != 12 ||
			l->order_n != 15 || l->order_n != 1)
	{
		if (l->arg_lab[0] == NULL)
			ft_printf("%%%i", l->arg[0]);
		else
			ft_put_col(2, 0, l);
	}
	else
		ft_printf("r%-18i", l->arg[0]);
	write(1, "\n", 1);
}

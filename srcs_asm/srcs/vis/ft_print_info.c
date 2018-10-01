/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:04:35 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/18 18:58:15 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_arrange_space(int size)
{
	int i;

	i = 20 - size * 4;
	while (--i)
		write(1, " ", 1);
}

static void	write_good(int val, int size)
{
	if (size == 4)
	{
		ft_printf("%-4i", (val & 0xff000000) >> 24);
		ft_printf("%-4i", (val & 0xff0000) >> 16);
	}
	if (size == 2 || size == 4)
		ft_printf("%-4i", (val & 0xff00) >> 8);
	ft_printf("%-4i", val & 0xff);
	ft_arrange_space(size);
}

static void	ft_print_inv(t_line *l)
{
	int i;

	i = -1;
	write(1, "\t\t", 2);
	if (l->arg_size[0])
		ft_printf("%-2i", l->arg_size[0]);
	if (l->arg_size[1])
		ft_printf("- %-2i", l->arg_size[1]);
	else
		write(1, "\t  ", 3);
	if (l->arg_size[2])
		ft_printf("- %-2i", l->arg_size[2]);
	else if (l->arg_size[1])
		write(1, "    ", 4);
	while (++i < 3)
	{
		if (l->arg_size[i])
			write_good(l->arg[i], l->arg_size[i]);
	}
	write(1, "\n", 1);
}

void		ft_print_info(t_line *l)
{
	ft_printf("\t\t%-4i", l->order_n);
	if (l->ocp != 1)
		ft_printf("\e[38;5;239m%-6i\e[0m", l->ocp);
	else
		ft_printf("\e[38;5;239m%-6s\e[0m", "---");
	if (l->arg_size[0])
		ft_printf("%-19i", l->arg[0]);
	if (l->arg_size[1])
		ft_printf("%-19i", l->arg[1]);
	if (l->arg_size[2])
		ft_printf("%-19i", l->arg[2]);
	write(1, "\n", 1);
	ft_print_inv(l);
}

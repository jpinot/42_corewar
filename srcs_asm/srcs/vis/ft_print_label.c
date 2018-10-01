/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 19:28:53 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/30 21:53:58 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_print_color(t_label *label)
{
	int	i;

	i = -1;
	if (label->color)
		ft_printf("\e[38;5;%im", label->color);
	while (label->name[++i] != ':')
		write(1, &label->name[i], 1);
	write(1, "\e[37m", 5);
	if (label->color == 0)
		ft_putstr(" \e[38;5;239m(no call)\e[0m");
}

int			ft_print_label(t_line *line)
{
	int		i;
	char	*s;

	s = line->line;
	i = 0;
	ft_printf("%-11i: ", line->pos);
	ft_print_color(line->label);
	write(1, "\n", 1);
	return (i);
}

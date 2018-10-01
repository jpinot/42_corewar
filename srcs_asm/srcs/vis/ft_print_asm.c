/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_asm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 18:08:37 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/25 17:38:53 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static void	ft_print_header(t_header h, int size)
{
	int i;

	i = -1;
	ft_putstr("ANOTED VERSION\nProgram size: ");
	ft_putnbr(size);
	ft_putstr(" bytes\nName:         \"");
	while (++i <= h.name_size)
		ft_putchar(h.prog_name[i]);
	ft_putstr("\nComment:      \"");
	i = -1;
	while (++i <= h.comment_size)
		ft_putchar(h.comment[i]);
	ft_putstr("\n\n");
}

void		ft_print_asm(t_header header,
		t_line *line, t_label **label, int size)
{
	t_line	*tmp;

	tmp = line->next;
	ft_print_header(header, size);
	line = ft_label_to_pos(line, label);
	while (tmp)
	{
		if (tmp->label)
			ft_print_label(tmp);
		if (tmp->order_n)
		{
			ft_print_order(tmp);
			ft_print_info(tmp);
		}
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	ft_delstruct(label, line);
	ft_strdel(&header.name_line);
	ft_strdel(&header.comment_line);
}

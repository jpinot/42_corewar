/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:39:59 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/01 14:40:37 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static t_line	*ft_nullarg(t_line *f)
{
	f->arg_lab[0] = NULL;
	f->arg_lab[1] = NULL;
	f->arg_lab[2] = NULL;
	f->lab_color[0] = 0;
	f->lab_color[1] = 0;
	f->lab_color[2] = 0;
	f->arg_size[0] = 0;
	f->arg_size[1] = 0;
	f->arg_size[2] = 0;
	f->ocp = 0;
	f->pos = 0;
	return (f);
}

t_line			*ft_newline(t_label *l, int ord_n, char *line, int w)
{
	t_line	*file;

	if (!(file = (t_line *)malloc(sizeof(t_line))))
		exit(-1);
	if (l)
		file->label = l;
	else
		file->label = NULL;
	if (line)
		file->line = line;
	else
		file->line = NULL;
	file->order_n = ord_n;
	file->w = w;
	file = ft_nullarg(file);
	file->next = NULL;
	return (file);
}

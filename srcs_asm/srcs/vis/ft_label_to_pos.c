/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_to_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:38:10 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/18 18:55:58 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static t_line	*extract_color(t_line *line, t_label *label, int pos, int color)
{
	line->arg[pos] = label->pos - line->pos;
	if (label->color)
		line->lab_color[pos] = label->color;
	else
	{
		label->color = color;
		line->lab_color[pos] = color;
	}
	return (line);
}

static t_line	*ft_extract_label_color(t_line *line,
		t_label *label, int pos, int color)
{
	t_label *tmp;

	if (label == NULL)
		ft_error_label(0, 1, line->arg_lab[pos]);
	tmp = NULL;
	if (ft_strcmp_to(label->name, line->arg_lab[pos]))
		return (extract_color(line, label, pos, color));
	else if (label->copy != NULL)
		tmp = label->copy;
	while (tmp)
	{
		if (ft_strcmp_to(tmp->name, line->arg_lab[pos]))
			return (extract_color(line, label, pos, color));
		tmp = tmp->copy;
	}
	ft_error_label(0, 1, line->arg_lab[pos]);
	return (0);
}

static int		manage_color(int color)
{
	if (color == 7)
		color = 8;
	if (color == 15)
		color = 20;
	if (color == 225)
		color = 1;
	return (color);
}

t_line			*ft_label_to_pos(t_line *bgn, t_label **label)
{
	t_line	*line;
	int		i;
	int		color;

	line = bgn->next;
	color = 1;
	while (line)
	{
		i = -1;
		while (++i < 3)
		{
			if (line->arg_lab[i])
			{
				line = ft_extract_label_color(line,
						label[line->arg[i]], i, color);
				color++;
			}
		}
		line = line->next;
		color = manage_color(color);
	}
	return (bgn);
}

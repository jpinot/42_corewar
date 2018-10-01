/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_label.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:05:46 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/25 18:03:33 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

MAX_CAST	ft_extract_label_line(t_line *line, t_label *label, int pos)
{
	t_label *tmp;

	if (label == NULL)
		ft_error_label(0, 1, line->arg_lab[pos]);
	tmp = NULL;
	if (ft_strcmp_to(label->name, line->arg_lab[pos]))
		return (label->pos - line->pos);
	else if (label->copy != NULL)
		tmp = label->copy;
	while (tmp)
	{
		if (ft_strcmp_to(tmp->name, line->arg_lab[pos]))
			return (tmp->pos - line->pos);
		tmp = tmp->copy;
	}
	ft_error_label(0, 1, line->arg_lab[pos]);
	return (0);
}

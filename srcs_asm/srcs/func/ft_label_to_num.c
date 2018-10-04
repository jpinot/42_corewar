/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label_to_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:25:53 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/04 19:10:58 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_line	*ft_label_to_num(t_line *line, t_label **label)
{
	t_line	*tmp;
	int		i;

	tmp = line->next;
	while (tmp)
	{
		if (tmp->order_n)
		{
			i = -1;
			while (++i < 3)
				if (tmp->arg_lab[i])
					tmp->arg[i] = ft_extract_label_line(tmp,
							label[tmp->arg[i]], i);
		}
		tmp = tmp->next;
	}
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_new_label.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:52:22 by jpinyot           #+#    #+#             */
/*   Updated: 2018/10/01 16:02:03 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

static int		ft_cmpr_str(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s1[++i] && s2[i] && s1[i] != ':' && s2[i] != ':')
	{
		if (s1[i] != s2[i])
			return (0);
	}
	if (s1[i] == ':' && s2[i] == ':')
		return (1);
	return (0);
}

static t_label	**add_to_copy(t_label **label, int id, char *l)
{
	t_label *tmp;

	tmp = label[id];
	if (ft_cmpr_str(tmp->name, l))
		ft_error_label(0, 0, l);
	while (tmp->copy)
	{
		if (ft_cmpr_str(tmp->copy->name, l))
			ft_error_label(0, 0, l);
		tmp = tmp->copy;
	}
	tmp->copy = ft_newlabel(l, id);
	label[HASH_SIZE - 1] = tmp->copy;
	return (label);
}

t_label			**ft_add_new_label(t_label **label, int id, char *l, int i)
{
	id = ft_hash_it(id, HASH_SIZE - 1);
	if (label[id] == NULL)
	{
		label[id] = ft_newlabel(&l[i], id);
		label[HASH_SIZE - 1] = label[id];
	}
	else
		return (add_to_copy(label, id, &l[i]));
	return (label);
}

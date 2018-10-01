/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlabel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:39:23 by jpinyot           #+#    #+#             */
/*   Updated: 2018/09/17 19:25:45 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

t_label		*ft_newlabel(char *name, int id)
{
	t_label *lab;

	if (!(lab = (t_label *)malloc(sizeof(t_label))))
		exit(-1);
	if (name)
		lab->name = name;
	else
		lab->name = NULL;
	lab->id = id;
	lab->pos = -1;
	lab->color = 0;
	lab->copy = NULL;
	return (lab);
}

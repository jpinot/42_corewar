/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:45:47 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/01 18:50:16 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static IND_CAST	charge_ind(const unsigned int pos)
{
	unsigned char	i;
	uint8_t			num[IND_SIZE];

	if ((pos + IND_SIZE) < MEM_SIZE)
		*((IND_CAST *)(num)) = *((IND_CAST *)(g_mem + pos));
	else
	{
		i = 0;
		while (i < IND_SIZE)
		{
			num[i] = g_mem[(pos + i) % MEM_SIZE];
			i++;
		}
	}
	invert_bytes(num, IND_SIZE);
	return (*((IND_CAST *)(num)));
}

void			core_fork(t_pc *pc)
{
	unsigned int	pos;
	IND_CAST		new_i;
	t_pc			*new_pc;
	unsigned char	i;

	i = 0;
	pos = pc->pc;
	new_i = ft_mod(pos + (charge_ind(pos + 1) % IDX_MOD), MEM_SIZE);
	if (!(new_pc = (t_pc *)malloc(sizeof(t_pc))))
		ft_error("Error: malloc failed in core_fork.\n");
	*new_pc = (t_pc){pc->carry, new_i, 0, {{0}}, pc->id, 0, pc->live, g_nb_pc_total, g_pc};
	while (i < REG_NUMBER)
	{
		*((REG_CAST *)(new_pc->reg[i])) = *((REG_CAST *)(pc->reg[i]));
		i++;
	}
	g_pc = new_pc;
	g_nb_pc++;
	g_nb_pc_total++;
	pc->pc = (pos + 1 + IND_SIZE) % MEM_SIZE;
}

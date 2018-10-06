/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_core_fork.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:17:20 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/01 19:00:52 by mrodrigu         ###   ########.fr       */
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

void			instruc_core_fork(t_pc *pc)
{
	unsigned int	pos;
	IND_CAST		new_i;
	IND_CAST		indirect;
	t_pc			*new_pc;
	unsigned char	i;

	i = 0;
	pos = pc->pc;
	indirect = charge_ind(pos + 1);
	new_i = pos + (indirect % IDX_MOD);
	if (!(new_pc = (t_pc *)malloc(sizeof(t_pc))))
		ft_error("Error: malloc failed in core_fork.\n");
	*new_pc = (t_pc){pc->carry, ft_mod(new_i, MEM_SIZE), 0, {{0}}, pc->id, 0, pc->live, g_nb_pc_total, g_pc};
	while (i < REG_NUMBER)
	{
		*((REG_CAST *)(new_pc->reg[i])) = *((REG_CAST *)(pc->reg[i]));
		i++;
	}
	ft_printf("P %4d | fork %d (%d)\n", pc->pc_num + 1, indirect, new_i);
	g_pc = new_pc;
	g_nb_pc++;
	g_nb_pc_total++;
	pc->pc = (pos + 1 + IND_SIZE) % MEM_SIZE;
}

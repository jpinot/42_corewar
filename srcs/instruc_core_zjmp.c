/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_core_zjmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 16:46:02 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/29 13:27:30 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static IND_CAST	charge_ind(const unsigned int pos)
{
	uint8_t			num[IND_SIZE];
	unsigned char	i;

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

void			instruc_core_zjmp(t_pc *pc)
{
	unsigned int	pos;
	int				jump_pos;

	pos = pc->pc;
	jump_pos = charge_ind(pos + 1);
	if (pc->carry)
	{
		pc->pc = ft_mod(pos + (jump_pos % IDX_MOD), MEM_SIZE);
		ft_printf("P %4d | zjmp %d OK\n", pc->pc_num + 1, jump_pos);
	}
	else
	{
		pc->pc = (pos + 1 + IND_SIZE) % MEM_SIZE;
		ft_printf("P %4d | zjmp %d FAILED\n", pc->pc_num + 1, jump_pos);
	}
}

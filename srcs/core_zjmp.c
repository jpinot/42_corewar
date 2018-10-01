/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 14:54:03 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/28 18:42:47 by mrodrigu         ###   ########.fr       */
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

void			core_zjmp(t_pc *pc)
{
	unsigned int pos;

	pos = pc->pc;
	if (pc->carry)
	{
		pc->pc = ft_mod(pos + (charge_ind(pos + 1) % IDX_MOD), MEM_SIZE);
//		ft_printf("zjmp: EL pc ha saltado a %d\n", pc->pc);
	}
	else
		pc->pc = (pos + 1 + IND_SIZE) % MEM_SIZE;
}

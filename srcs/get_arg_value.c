/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:14:50 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/25 16:20:40 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static void		get_ind(const t_pc *pc, const IND_CAST ind, t_arg *arg, const unsigned char restriction)
{
	int 			inc;
	unsigned char	i;

	if (restriction)
		inc = pc->pc + (ind % IDX_MOD);
	else
		inc = pc->pc + ind;
	if ((inc + REG_SIZE) < MEM_SIZE && inc >= 0)
		*((REG_CAST *)(arg->arg)) = *((REG_CAST *)(g_mem + inc));
	else
	{
		i = 0;
		while (i < REG_SIZE)
		{
			arg->arg[i] = g_mem[ft_mod(inc + i, MEM_SIZE)];
			i++;
		}
	}
}

char			get_arg_value(t_arg *arg, const t_pc *pc, const unsigned char restriction)
{
	unsigned char	i;
	IND_CAST		ind;

	if (arg->type == REG_CODE)
	{
		if ((i = arg->arg[0] - 1) >= REG_NUMBER)
			return (0);
		*((REG_CAST *)(arg->arg)) = *((REG_CAST *)(pc->reg[i]));
	}
	else if (arg->type == IND_CODE)
	{
		ind = *((IND_CAST *)(arg->arg));
		invert_bytes(&ind, IND_SIZE);
		get_ind(pc, ind, arg, restriction);
	}
	return (1);
}

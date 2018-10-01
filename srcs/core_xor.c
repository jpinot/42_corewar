/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_xor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:57:11 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/25 16:20:41 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static char	verify_ocp(const unsigned char ocp)
{
	if ((0xC0 & ocp) == 0x0 ||//1
	    (0x30 & ocp) == 0x0 ||//2
	    (0xC & ocp) == 0x0 || (0xC & ocp) == 0x8 || (0xC & ocp) == 0xC)//3
		return (0);
	return (1);
}

static void	apply_xor(const t_arg arg1, const t_arg arg2, const t_pc *pc, const unsigned char reg_pos)
{
	*((REG_CAST *)(pc->reg[reg_pos])) = *((REG_CAST *)(arg1.arg)) ^ *((REG_CAST *)(arg2.arg));
}

void		core_xor(t_pc *pc)
{
	unsigned char	ocp;
	t_arg			arg1;
	t_arg			arg2;
	unsigned char	reg_pos;
	unsigned int	pos;

	pos = pc->pc;
	ocp = g_mem[(pos + 1) % MEM_SIZE];
	if (verify_ocp(ocp))
	{
		arg1 = (t_arg){0, 0, 0, 0x1, {0}};
		arg2 = (t_arg){1, 0, 0, 0x1, {0}};
		get_arg(ocp, pos, 0, &arg1);
		get_arg(ocp, pos, arg1.len, &arg2);
		reg_pos = g_mem[(pos + 2 + arg1.len + arg2.len) % MEM_SIZE] - 1;
		if (get_arg_value(&arg1, pc, 1) && get_arg_value(&arg2, pc, 1) && reg_pos < REG_NUMBER)
		{
			apply_xor(arg1, arg2, pc, reg_pos);
			pc->carry = (*((REG_CAST *)(pc->reg[reg_pos]))) ? 0x0 : 0x1;
		}
		pc->pc = (pos + 1 + 1 + arg1.len + arg2.len + 1) % MEM_SIZE;//and + ocp + arg1 + arg2 + rg
	}
	else
		pc->pc = (pc->pc + 1 + 1 + get_size_arg(ocp, 0, 1) + get_size_arg(ocp, 1, 1) + get_size_arg(ocp, 2, 1)) % MEM_SIZE;//and + ocp + arg1 + arg2 + arg3
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_core_and.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 20:19:55 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/29 20:50:22 by mrodrigu         ###   ########.fr       */
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

static void	apply_and(const t_arg arg1, const t_arg arg2, const t_pc *pc, const unsigned char reg_pos)
{
	REG_CAST	value1;
	REG_CAST	value2;

	value1 = *((REG_CAST *)(arg1.arg));
	value2 = *((REG_CAST *)(arg2.arg));
	*((REG_CAST *)(pc->reg[reg_pos])) = value1 & value2;
	invert_bytes(&value1, REG_SIZE);
	invert_bytes(&value2, REG_SIZE);
	ft_printf("P %4d | and %d %d r%d\n", pc->pc_num + 1, value1, value2, reg_pos + 1);
}

void		instruc_core_and(t_pc *pc)
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
			apply_and(arg1, arg2, pc, reg_pos);
			pc->carry = (*((REG_CAST *)(pc->reg[reg_pos]))) ? 0x0 : 0x1;
		}
		pc->pc = (pos + 1 + 1 + arg1.len + arg2.len + 1) % MEM_SIZE;//and + ocp + arg1 + arg2 + rg
//		ft_printf("and: y ahora el pc esta en %d\n", pc->pc);
	}
	else
		pc->pc = (pc->pc + 1 + 1 + get_size_arg(ocp, 0, 1) + get_size_arg(ocp, 1, 1) + get_size_arg(ocp, 2, 1)) % MEM_SIZE;//and + ocp + arg1 + arg2 + arg3
}

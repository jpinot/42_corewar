/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_core_sti.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 19:28:53 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/26 20:20:40 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"
#include "graphics.h"

static char	verify_ocp(const unsigned char ocp)
{
	if ((0xC0 & ocp) == 0x0 || (0xC0 & ocp) == 0x80 || (0xC0 & ocp) == 0xC0 ||
	    (0x30 & ocp) == 0x0 ||
	    (0xC & ocp) == 0x0 || (0xC & ocp) == 0xC)
		return (0);
	return (1);
}

static void	store_indirect(const unsigned char reg_pos, const t_arg arg2, const t_arg arg3, t_pc *pc)
{
	int 			inc;
	unsigned int	pos;
	unsigned char	i;

	pos = pc->pc;
	inc = (pos + ((*((REG_CAST *)(arg2.arg)) + *((REG_CAST *)(arg3.arg))) % IDX_MOD));
	i = 0;
	while (i < REG_SIZE)
	{
		g_mem[ft_mod(inc + i, MEM_SIZE)] = pc->reg[reg_pos][i];
		g_board[ft_mod(inc + i, MEM_SIZE)] = (t_board){pc->reg[reg_pos][i], NEW_DUR, pc->id + 1};
		i++;
	}
//	ft_printf("sti: ha puesto %d en %d", *((REG_CAST *)pc->reg[reg_pos]), inc);
}

void		graphics_core_sti(t_pc *pc)
{
	unsigned char 	ocp;
	t_arg			arg2;
	t_arg			arg3;
	unsigned char	reg_pos;
	unsigned int	pos;

	pos = pc->pc;
	ocp = g_mem[(pos + 1) % MEM_SIZE];
	if (verify_ocp(ocp))
	{
		reg_pos = g_mem[(pos + 2) % MEM_SIZE] - 1;
		arg2 = (t_arg){1, 0, 0, 0x0, {0}};
		arg3 = (t_arg){2, 0, 0, 0x0, {0}};
		get_arg(ocp, pos, 1, &arg2);
		get_arg(ocp, pos, 1 + arg2.len, &arg3);
		if (get_arg_value(&arg2, pc, 1) && get_arg_value(&arg3, pc, 1) && reg_pos < REG_NUMBER)
		{
			invert_bytes(arg2.arg, arg2.type == DIR_CODE ? IND_SIZE : REG_SIZE);
			invert_bytes(arg3.arg, arg3.type == DIR_CODE ? IND_SIZE : REG_SIZE);
			if (arg2.type == DIR_CODE)
				*((REG_CAST *)arg2.arg) = *((IND_CAST *)arg2.arg);
			if (arg3.type == DIR_CODE)
				*((REG_CAST *)arg3.arg) = *((IND_CAST *)arg3.arg);
			store_indirect(reg_pos, arg2, arg3, pc);
		}
		pc->pc = (pos + 1 + 1 + 1 + arg2.len + arg3.len) % MEM_SIZE;
//		ft_printf(" y ahora esta en: %d\n", pc->pc);
	}
	else
		pc->pc = (pos + 1 + 1 + get_size_arg(ocp, 0, 0) + get_size_arg(ocp, 1, 0) + get_size_arg(ocp, 2, 0)) % MEM_SIZE;//and + ocp + arg1 + arg2 + rg

}

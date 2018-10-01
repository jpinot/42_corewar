/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_core_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 20:10:40 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/29 13:27:36 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static void	add_reg(t_pc *pc, const unsigned char reg1, const unsigned char reg2, const unsigned char reg3)
{
	REG_CAST aux1;
	REG_CAST aux2;

	aux1 = *((REG_CAST *)pc->reg[reg1]);
	aux2 = *((REG_CAST *)pc->reg[reg2]);
	invert_bytes(&aux1, REG_SIZE);
	invert_bytes(&aux2, REG_SIZE);
	(*(REG_CAST *)pc->reg[reg3]) = aux1 + aux2;
	invert_bytes(pc->reg[reg3], REG_SIZE);
	ft_printf("P %4d | add r%d r%d r%d\n", pc->pc_num + 1, reg1 + 1, reg2 + 1, reg3 + 1);
	pc->pc = (pc->pc + 1 + 1 + 1 + 1 + 1) % MEM_SIZE;//ld + opc + reg1 + reg2 + reg3
	pc->carry = (*((REG_CAST *)(pc->reg[reg3]))) ? 0x0 : 0x1;//actualizar carry
}

void		instruc_core_add(t_pc *pc)
{
	unsigned int	pos;
	unsigned char	ocp;
	unsigned char	reg1;
	unsigned char	reg2;
	unsigned char	reg3;

	pos = pc->pc;
	ocp  = g_mem[(pos + 1) % MEM_SIZE];
	if ((0xFC & ocp) == 0x54 && (reg1 = g_mem[(pos + 2) % MEM_SIZE] - 1) < REG_NUMBER && (reg2 = g_mem[(pos + 3) % MEM_SIZE] - 1) < REG_NUMBER && (reg3 = g_mem[(pos + 4) % MEM_SIZE] - 1) < REG_NUMBER)
		add_reg(pc, reg1, reg2, reg3);
	else
		pc->pc = (pc->pc + 1 + 1 + get_size_arg(ocp, 0, 1) + get_size_arg(ocp, 1, 1) + get_size_arg(ocp, 2, 1)) % MEM_SIZE;//add, ocp, a1, a2, a3
}

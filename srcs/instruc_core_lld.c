/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_core_lld.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:13:52 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/03 14:17:02 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static void	load_direct(const unsigned char reg_pos, t_pc *pc)
{
	unsigned char	i;
	unsigned int	aux_pc;
	REG_CAST		print_num;

	aux_pc = pc->pc + 2;//jump ld + ocp
	if ((aux_pc + DIR_SIZE) < MEM_SIZE)
		*((REG_CAST *)(pc->reg[reg_pos])) = *((DIR_CAST *)(g_mem + aux_pc));
	else
	{
		i = 0;
		while (i < REG_SIZE && i < DIR_SIZE)
		{
			pc->reg[reg_pos][i] = g_mem[(aux_pc + i) % MEM_SIZE];
			i++;
		}
	}
	print_num = *((REG_CAST *)(pc->reg[reg_pos]));
	invert_bytes(&print_num, REG_SIZE);
	ft_printf("P %4d | lld %d r%d\n", pc->pc_num + 1, print_num, reg_pos + 1);
	pc->pc = (aux_pc + 1 + DIR_SIZE) % MEM_SIZE;//ld + ocp + reg + dir
	pc->carry = (*((REG_CAST *)pc->reg[reg_pos])) ? 0x0 : 0x1;
}

static void	load_indirect(const unsigned char reg_pos, t_pc *pc)
{
	int8_t			board_pos[IND_SIZE];
	unsigned char	i;
	unsigned int	aux_pc;
	int				inc;

	aux_pc = pc->pc + 2;
	if ((aux_pc + IND_SIZE) < MEM_SIZE)
		*((IND_CAST *)board_pos) = *((IND_CAST *)(g_mem + aux_pc));
	else
	{
		i = 0;
		while (i < IND_SIZE)
		{
			board_pos[i] = g_mem[(aux_pc + i) % MEM_SIZE];
			i++;
		}
	}
	invert_bytes(board_pos, IND_SIZE);
	inc = pc->pc + (*((IND_CAST *)board_pos) % IDX_MOD);
	if ((inc + DIR_SIZE) < MEM_SIZE && inc >= 0)
		*((REG_CAST *)pc->reg[reg_pos]) = *((DIR_CAST *)(g_mem + inc));
	else
	{
		i = 0;
		while (i < REG_SIZE && i < DIR_SIZE)
		{
			pc->reg[reg_pos][i] = g_mem[ft_mod(inc + i, MEM_SIZE)];
			i++;
		}
	}
//	ft_printf("P %4d | ld %d r%d\n", pc->pc_num + 1, *((IND_CAST *)(board_pos)), reg_pos + 1);
	ft_printf("P %4d | lld %d r%d\n", pc->pc_num + 1, invert_bytes_ret(*((REG_CAST *)(pc->reg[reg_pos])), REG_SIZE), reg_pos + 1);
	pc->pc = (aux_pc + 1 + IND_SIZE) % MEM_SIZE;//ld + ocp + ind + reg
	pc->carry = (*((REG_CAST *)pc->reg[reg_pos])) ? 0x0 : 0x1;
}

void		instruc_core_lld(t_pc *pc)
{
	unsigned int	pos;
	unsigned char	ocp;
	unsigned char	reg_pos;

	pos = pc->pc;
	ocp = g_mem[(pos + 1) % MEM_SIZE];
	if ((0xF0 & ocp) == 0x90 && (reg_pos = g_mem[(pos + 2 + DIR_SIZE) % MEM_SIZE] - 1) < REG_NUMBER)
		load_direct(reg_pos, pc);
	else if ((0xF0 & ocp) == 0xD0 && (reg_pos = g_mem[(pos + 2 + IND_SIZE) % MEM_SIZE] - 1) < REG_NUMBER)
		load_indirect(reg_pos, pc);
	else
		pc->pc = (pc->pc + 1 + 1 + get_size_arg(ocp, 0, 1) + get_size_arg(ocp, 1, 1)) % MEM_SIZE;//ld + ocp + a1 + a2
}

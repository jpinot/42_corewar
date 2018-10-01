/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 17:21:27 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/25 16:20:43 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"


static void	print_reg(const t_pc *pc, const unsigned char reg_pos)
{
	REG_CAST	aux_reg;

	aux_reg = *((REG_CAST *)pc->reg[reg_pos]);
	invert_bytes(&aux_reg, REG_SIZE);
	ft_putstr("Aff: ");
	ft_putchar(aux_reg);
	ft_putchar('\n');
}

void		core_aff(t_pc *pc)
{
	unsigned char	ocp;
	unsigned int	pos;
	unsigned char	reg_pos;

	pos = pc->pc;
	ocp = g_mem[(pos + 1) % MEM_SIZE];
	if ((0xC0 & ocp) == 0x40 && (reg_pos = g_mem[(pos + 1) % MEM_SIZE] - 1) < REG_NUMBER)
	{
		print_reg(pc, reg_pos);
		pc->pc = (pos + 1 + 1 + 1) % MEM_SIZE;
	}
	else
		pc->pc = ((pc->pc + 1 + 1 + get_size_arg(ocp, 0, 1)) % MEM_SIZE);//aff + ocp + rg
}

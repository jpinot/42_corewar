/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deaths_launch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:39:55 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/28 21:39:56 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static void	init_func(t_op *ops)
{
	ops[0] = (t_op){core_live, 10};
	ops[1] = (t_op){core_ld, 5};
	ops[2] = (t_op){core_st, 5};
	ops[3] = (t_op){core_add, 10};
	ops[4] = (t_op){core_sub, 10};
	ops[5] = (t_op){core_and, 6};
	ops[6] = (t_op){core_or, 6};
	ops[7] = (t_op){core_xor, 6};
	ops[8] = (t_op){core_zjmp, 20};
	ops[9] = (t_op){core_ldi, 25};
	ops[10] = (t_op){core_sti, 25};
	ops[11] = (t_op){core_fork, 800};
	ops[12] = (t_op){core_lld, 10};
	ops[13] = (t_op){core_lldi, 50};
	ops[14] = (t_op){core_lfork, 1000};
	ops[15] = (t_op){core_aff, 2};
}

static void	exe_pc(t_op *ops)
{
	t_pc			*aux_pc;
	unsigned char	op;
	unsigned int	wc;

	aux_pc = g_pc;
	while (aux_pc)
	{
		wc = aux_pc->wait_cycles;
		if (wc == 0 && (op = g_mem[aux_pc->pc] - 1) < NB_INSTRUCTIONS)
		{
			aux_pc->wait_cycles = ops[op].cycles_wait - 1;
			aux_pc->op = op;
		}
		else if (wc > 1)
			aux_pc->wait_cycles--;
		else if (wc == 1)
		{
			ops[aux_pc->op].func(aux_pc);
			aux_pc->wait_cycles--;
		}
		else
			aux_pc->pc = (aux_pc->pc + 1) % MEM_SIZE;
		aux_pc = aux_pc->next;
	}
	g_nb_cycles++;
}

void		deaths_launch(void)
{
	int 	i;
	t_op			ops[NB_INSTRUCTIONS];

	init_func(ops);
	while (g_pc)
	{
		i = 0;
		while (1)
		{
			exe_pc(ops);
			i++;
			if (i >= g_cycle_to_die)
				break ;
		}
		check_cycle_to_die_deaths();
	}
}

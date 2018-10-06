/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:47:26 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/04 15:46:28 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include "basic_corewar.h"


static void	init_func(t_op *ops)
{
	ops[0] = (t_op){core_live, 10};
	ops[1] = (t_op){core_ld, 5};
	ops[2] = (t_op){graphics_core_st, 5};
	ops[3] = (t_op){core_add, 10};
	ops[4] = (t_op){core_sub, 10};
	ops[5] = (t_op){core_and, 6};
	ops[6] = (t_op){core_or, 6};
	ops[7] = (t_op){core_xor, 6};
	ops[8] = (t_op){core_zjmp, 20};
	ops[9] = (t_op){core_ldi, 25};
	ops[10] = (t_op){graphics_core_sti, 25};
	ops[11] = (t_op){core_fork, 800};
	ops[12] = (t_op){core_lld, 10};
	ops[13] = (t_op){core_lldi, 50};
	ops[14] = (t_op){core_lfork, 1000};
	ops[15] = (t_op){core_aff, 2};
}
static void	init_board()
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	id;

	i = 0;
	id = 0;
	ft_memset(g_board, 0, sizeof(t_board) * MEM_SIZE);
	j = 0;
	while (j < MEM_SIZE)
	{
		i = 0;
		while (i < g_players[id].prog_size)
		{
			g_board[j].mem = g_mem[j];
			g_board[j].id = id + 1;
			i++;
			j++;
		}
		id++;
		j = id * (MEM_SIZE / g_n_players);
	}
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

static void	init_graph(void)
{
	unsigned int	i;
	t_pc			*aux_pc;

	if (!(g_aux = (t_graphics *)malloc(sizeof(t_graphics))))
		ft_error("Error: malloc failed in init_graph\n");
	init_board();
	ft_memcpy(g_aux->board, g_board, sizeof(t_board) * MEM_SIZE);
	ft_memcpy(g_aux->players, g_players, sizeof(t_player) * g_n_players);
	g_aux->cycle_to_die = g_cycle_to_die;
	g_aux->cycle_pre_die = 0;
	g_aux->cycle = g_nb_cycles;
	g_aux->nb_pc = g_nb_pc;
	if (!(g_aux->pcs = (unsigned int *)malloc(sizeof(unsigned int) * g_nb_pc)))
		ft_error("Error: malloc failed in unit_graph\n");
	i = 0;
	aux_pc = g_pc;
	while (i < g_nb_pc && aux_pc)
	{
		g_aux->pcs[i] = (((unsigned int)aux_pc->id) << 24) | aux_pc->pc;
		aux_pc = aux_pc->next;
		i++;
	}
	g_aux->prog_end = 0x0;
	g_aux->next = NULL;
	g_graph_tail = g_aux;
	g_frame = g_aux;
	g_aux = NULL;
}

static void	add_frame(void)
{
	pthread_mutex_lock(&g_lock);
	if (g_frame)
	{
		g_graph_tail->next = g_aux;
		g_graph_tail = g_graph_tail->next;
	}
	else
	{
		g_frame = g_aux;
		g_graph_tail = g_frame;
	}
	g_aux = NULL;
	pthread_mutex_unlock(&g_lock);
}

static void	end_frame(void)
{
	if (!(g_aux = (t_graphics *)malloc(sizeof(t_graphics))))
		ft_error("Error: malloc failed in end_frame\n");
	g_aux->prog_end = 0x1;
	add_frame();
}



void		*graphic_thread(void *arg)
{
	int 			i;
	t_op			ops[NB_INSTRUCTIONS];

	init_func(ops);
	init_graph();
	while (g_pc)
	{
		i = 0;
		while (1)
		{
			exe_pc(ops);
			new_frame(i);
			add_frame();
			i++;
			if (i >= g_cycle_to_die)
				break ;
		}
		check_cycle_to_die();
	}
	end_frame();
	return ((void *)NULL);
}

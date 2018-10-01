/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:30:40 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/26 20:34:31 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"
#include "graphics.h"

void	new_frame(const int j)
{
	unsigned int i;
	t_pc			*aux_pc;

	if (!g_aux)
	{
		if (!(g_aux = (t_graphics *)malloc(sizeof(t_graphics))))
			ft_error("malloc failed in new_frame");
		i = 0;
		while (i < MEM_SIZE)
		{
			g_aux->board[i] = g_board[i];
			if (g_board[i].new)
				g_board[i].new--;
			i++;
		}
		ft_memcpy(g_aux->players, g_players, sizeof(t_player) * g_n_players);
		g_aux->cycle_to_die = g_cycle_to_die;
		g_aux->cycle_pre_die = j;
		g_aux->cycle = g_nb_cycles;
		g_aux->nb_pc = g_nb_pc;
		if (!(g_aux->pcs = (unsigned int *)malloc(sizeof(unsigned int) * g_nb_pc)))
			ft_error("malloc failed in unit_graph");
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
	}
}

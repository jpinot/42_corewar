/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc_core_live.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:12:16 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/30 19:02:47 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static DIR_CAST	take_live_nb(const unsigned int pos)
{
	int8_t			live_nb[DIR_SIZE];
	unsigned char	i;

	if ((pos + DIR_SIZE) < MEM_SIZE)
		return (*((DIR_CAST *)(g_mem + pos)));
	else
	{
		i = 0;
		while (i < DIR_SIZE)
		{
			live_nb[i] = g_mem[(pos + i) % MEM_SIZE];
			i++;
		}
		return (*((DIR_CAST *)live_nb));
	}
}

void			instruc_core_live(t_pc *pc)
{
	unsigned int	pos;
	int32_t			live_nb;
	unsigned char	i;

	i = 0;
	pos = pc->pc;
	live_nb = take_live_nb(pos + 1);//jump live order
	invert_bytes(&live_nb, sizeof(int32_t));
	while (i < g_n_players)
	{
		if (g_players[i].player_nb == live_nb)
		{
			g_players[i].live_counter++;
			g_players[i].last_live = g_nb_cycles;
			g_winner = i;
			break ;
		}
		i++;
	}
//	ft_printf("P %4d | live %d(%d)(CTD %d)\n", pc->pc_num + 1, live_nb, g_nb_cycles, g_cycle_to_die);
	ft_printf("P %4d | live %d\n", pc->pc_num + 1, live_nb);
	g_lives++;
	pc->live = 1;
	pc->pc = (pos + 1 + 4) % MEM_SIZE;
//	ft_printf("live: y ahora el pc esta en %d\n", pc->pc);
}

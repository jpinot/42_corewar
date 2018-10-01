/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle_to_die_deaths.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:42:38 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/29 23:33:31 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"

static char	check_head(void)
{
	t_pc *aux_pc;

	while (g_pc && !g_pc->live)
	{
		ft_printf("El pc %u ha muerto.(CTD %d) pos %d\n", g_pc->pc_num + 1, g_cycle_to_die, g_pc->pc);
		aux_pc = g_pc->next;
		free(g_pc);
		g_pc = aux_pc;
		g_nb_pc--;
	}
	if (!g_pc)
		return(0);
	g_pc->live = 0;
	return (1);
}

static void	check_body(void)
{
	t_pc	*current_pc;
	t_pc	*previous_pc;
	t_pc	*next_pc;

	previous_pc = g_pc;
	current_pc = g_pc->next;
	while (current_pc)
	{
		if (current_pc->live)
		{
			current_pc->live = 0;
			previous_pc = current_pc;
			current_pc = current_pc->next;
		}
		else
		{
			ft_printf("El pc %u ha muerto.(CTD %d) pos %d\n", current_pc->pc_num + 1, g_cycle_to_die, current_pc->pc);
			next_pc = current_pc->next;
			previous_pc->next = next_pc;
			free(current_pc);
			current_pc = next_pc;
			g_nb_pc--;
		}
	}
}

void		check_cycle_to_die_deaths(void)
{
	static unsigned int checks = 0;

	if (!check_head())
		return ;
	check_body();
	if (g_lives >= NBR_LIVE)
	{
		g_cycle_to_die -= CYCLE_DELTA;
		checks = 0;
	}
	else
	{
		checks++;
		if (checks == MAX_CHECKS)
		{
			g_cycle_to_die -= CYCLE_DELTA;
			checks = 0;
		}
	}
	g_lives = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_launch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 15:17:54 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/10/06 01:13:14 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_corewar.h"
#include "graphics.h"

t_sdl			*g_graph;
t_graphics		*g_frame;
t_graphics		*g_graph_tail;
t_graphics		*g_aux;
pthread_mutex_t	g_lock;
int				g_cycle_cuant;
unsigned int	g_pause;
unsigned int	g_hexl;
unsigned int	g_step;
t_board			g_board[MEM_SIZE];

static void			move_frame(void)
{
	t_graphics	*aux;
	int			i;

	i = -1;
	while (g_frame && !g_frame->prog_end && ++i < g_cycle_cuant)
	{
		pthread_mutex_lock(&g_lock);
		aux = g_frame;
		g_frame = g_frame->next;
		free(aux->pcs);
		free(aux);
		pthread_mutex_unlock(&g_lock);
	}
}

static void			graphic_main_bucle(void)
{
	int			running;

	running = 1;
	while (running)
	{
		ft_events(&running);
		if (g_frame)
		{
			if (!g_frame->prog_end)
			{
				ft_board_to_screen(g_frame->board);
				ft_update_info(g_frame->players, g_frame->cycle_pre_die);
			}
			if ((!g_pause || g_step) && !g_frame->prog_end)
				move_frame();
			ft_set_back_to_front();
			g_step = 0;
		}
	}
}

void				graphic_launch(const unsigned int flags)
{
	pthread_t		thread;
	void			*status;
	int				running;

	running = 1;
	pthread_mutex_init(&g_lock, NULL);
	g_pause = 1;
	g_hexl = 1;
	g_step = 0;
	g_cycle_cuant = 1;
	if ((pthread_create(&thread, NULL, graphic_thread, (void *)NULL)))
		ft_error("thread can not be created");
	ft_ini_graphics(flags);
	graphic_main_bucle();
	ft_quit_graphics();
	pthread_mutex_destroy(&g_lock);
	pthread_join(thread, &status);
}

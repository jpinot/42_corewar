/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_player_interf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:07:14 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/25 20:24:19 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void			exe_pc(t_pc *pc, t_arena *arena, t_data *data)
{
	unsigned char op_nb;

	op_nb = (arena->board[pc->pc % MEM_SIZE].mem) - 1;
	if (pc->wait_cycles > 1)
	{
		pc->wait_cycles--;
		return ;
	}
	else if (pc->wait_cycles == 1)
	{
		pc->wait_cycles--;
//		ft_printf("executing.. %d\n", op_nb);
			// data->func[op_nb](player, pc, arena, data);
			data->func[pc->op](pc, arena, data);
	}
	else
	{
		if (op_nb <= 15)
		{
			pc->wait_cycles = (data->op[op_nb].mana) - 1;
			pc->op = op_nb;
		}
		else
			pc->pc = (pc->pc + 1) % MEM_SIZE;
	}
}

static int			pause_button(t_data *data, t_sdl *Graph, unsigned int pause)
{
	SDL_Surface *button;
	int			rtn;
	int			i;
	char		*pixel;
	int			pitch;
	int			hall_dim;

	hall_dim = Graph->square_info->w - Graph->player_nbr->w * 21;
	if (pause)
		button = data->mods->pause_surf[0];
	else
		button = data->mods->pause_surf[1];
	SDL_LockTexture(Graph->info_text, &(SDL_Rect){Graph->square_info->w - hall_dim + (hall_dim - button->w) / 2, 100, button->w, button->h}, (void **)&pixel, &pitch);
	SDL_LockSurface(button);
	i = -1;
	while (++i < button->h)
		memcpy(pixel + i * pitch, button->pixels + i * button->pitch, button->pitch);
	SDL_UnlockSurface(button);
	SDL_UnlockTexture(Graph->info_text);
	return (pause ? 0 : 0x1);
}

void 				exe_players_interf(t_data *data)
{
	unsigned int k;
	unsigned int t;
	SDL_Event	event;

	data->i = 0;

	fill_r1(data);
	while(data->cycle_to_die > 0 && data->mods->running)
	{
		t = 0;
		while (t < data->cycle_to_die && data->mods->running)
		{
			data->mods->step = 0;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					data->mods->running = 0;
				else if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_ESCAPE)
						data->mods->running = SDL_FALSE;
					else if (event.key.keysym.sym == SDLK_SPACE)
						data->mods->pause = pause_button(data, data->arena->Graph, data->mods->pause);
					else if (event.key.keysym.sym == SDLK_RIGHT)
						data->mods->step = 1;
					else if (event.key.keysym.sym == SDLK_i)
						data->mods->info = data->mods->info ? 0 : 1;
				}
			}
			if (data->mods->pause || data->mods->step)
			{
				k = data->nb_pc;
				while (k)
				{
					if (data->pc[k - 1].active)
						exe_pc((data->pc) + k - 1, data->arena, data); //TODO ejecutamos el turno cycle to die
					k--;
				}
				t++;
				data->nb_cycles++;
			}
			ft_board_to_screen(data->arena->Graph, data->arena->board, data);
			ft_update_info(data->arena->Graph, data, t - 1);
			ft_set_back_to_front(data->arena->Graph, data);
		}
		check_live_count(data);
	}
	check_winner(data->players, data->n_players);
}

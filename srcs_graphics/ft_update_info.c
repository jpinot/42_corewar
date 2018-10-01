/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 16:39:44 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/09/30 22:10:10 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void		update_digit(SDL_Rect pos, char digit[2],
		int mode)
{
	SDL_Surface	*tmp;
	t_font		font;
	SDL_Surface *num_surf;

	if (mode == GENERAL_NBR_FONT)
		num_surf = g_Graph->general_nbr;
	else
		num_surf = g_Graph->player_nbr;
	font = g_Graph->font[mode];
	tmp = TTF_RenderUTF8_Blended(font.font, digit, font.color);
	SDL_FillRect(num_surf, &(SDL_Rect){1, 1, num_surf->w - 2, num_surf->h - 2},
		SDL_MapRGBA(num_surf->format, 0, 0, 0, 255));
	SDL_BlitSurface(tmp, NULL, num_surf, &(SDL_Rect){(num_surf->w - tmp->w) / 2,
		(num_surf->h - tmp->h) / 2 + 2, tmp->w, tmp->h});
	ft_surf_to_text(g_Graph->info_text, num_surf, &pos);
	SDL_FreeSurface(tmp);
}

static void		update_number(unsigned int info, SDL_Rect pieze, int mode)
{
	int		pos;
	char	*digits;

	digits = "0123456789";
	pos = 1;
	while (info > 0)
	{
		update_digit((SDL_Rect){pieze.x + (10 - pos) * (pieze.w - 1),
				pieze.y, pieze.w, pieze.h}, (char[2]){digits[info % 10], 0},
				mode);
		if (!(info /= 10))
			return ;
		pos++;
	}
	while (pos < 10)
	{
		update_digit((SDL_Rect){pieze.x + (10 - pos) * (pieze.w - 1),
				pieze.y, pieze.w, pieze.h}, "0\0", mode);
		pos++;
	}
}

static void		update_players(const int cicle_pre_die, const t_player *players,
		unsigned int lives[MAX_PLAYERS])
{
	unsigned int		i;

	i = 0;
	while (i < g_n_players)
	{
		ft_check_health(g_frame->cycle_to_die, i, cicle_pre_die, players);
		g_Graph->font[PLAYER_NBR_FONT].color = ft_sdl_color(i);
		if (!cicle_pre_die)
			update_number(0, g_Graph->info.cicles_play[i],
					PLAYER_NBR_FONT);
		if (players[i].live_counter != lives[i])
		{
			update_number(players[i].live_counter,
					g_Graph->info.cicles_play[i], PLAYER_NBR_FONT);
			update_number(players[i].last_live,
				g_Graph->info.lst_life[i], PLAYER_NBR_FONT);
			lives[i] = players[i].live_counter;
		}
		i++;
	}
}

void			ft_update_info(const t_player *players, const int cicle_pre_die)
{
	static unsigned int	nbr_pcs = 0;
	static unsigned int lives[MAX_PLAYERS] = {0};

	update_number(g_frame->cycle, *g_Graph->info.cicles_gen, GENERAL_NBR_FONT);
	if (!cicle_pre_die)
	{
		update_number(0,
			*g_Graph->info.cicle_to_die, GENERAL_NBR_FONT);
		update_number(g_frame->cycle_to_die,
			*g_Graph->info.cicle_to_die, GENERAL_NBR_FONT);
	}
	if (nbr_pcs != g_frame->nb_pc)
	{
		if (nbr_pcs > g_frame->nb_pc)
			update_number(0,
				*g_Graph->info.processos, GENERAL_NBR_FONT);
		update_number(g_frame->nb_pc, *g_Graph->info.processos,
			GENERAL_NBR_FONT);
		nbr_pcs = g_frame->nb_pc;
	}
	update_players(cicle_pre_die, players, lives);
}

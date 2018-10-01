/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_data_surfs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 22:02:57 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/30 21:53:39 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void		ini_number(int mode, SDL_Surface **number, SDL_Rect square_info)
{
	*number = SDL_CreateRGBSurfaceWithFormat(0, square_info.w, square_info.h,
			32, g_Graph->rack->format->format);
	if (SDL_FillRect(*number, NULL, SDL_MapRGBA(g_Graph->rack->format,
		255, 255, 255, 255)))
		ft_sdl_error("SDL_FillRect", MODE_SDL);
	if (SDL_FillRect(*number, &(SDL_Rect){1, 1, (*number)->w - 2,
		(*number)->h - 2}, SDL_MapRGBA((*number)->format, 0, 0, 0, 255)))
		ft_sdl_error("SDL_FillRect", MODE_SDL);
	while (g_Graph->font[mode].w + 10 < (*number)->w && g_Graph->font[mode].h +
			10 < (*number)->h)
	{
		if (g_Graph->font[mode].font)
			TTF_CloseFont(g_Graph->font[mode].font);
		if (!(g_Graph->font[mode].font = TTF_OpenFont("./whitrabt.ttf",
				++g_Graph->font[mode].font_size)))
			ft_sdl_error("TTF_OpenFont", MODE_TTF);
		if (TTF_SizeUTF8(g_Graph->font[mode].font, "0", &g_Graph->font[mode].w,
			&g_Graph->font[mode].h))
			ft_sdl_error("TTF_SizeUTF8", MODE_SDL);
	}
}

static void		ini_info_rects(void)
{
	SDL_Rect *tmp;

	tmp = (SDL_Rect *)malloc(sizeof(SDL_Rect));
	g_Graph->info.cicles_gen = tmp;
	*g_Graph->info.cicles_gen = (SDL_Rect){0, 0, g_Graph->square_info->w / 20,
			g_Graph->square_info->h / 6};
	g_Graph->info.cicle_to_die = (SDL_Rect *)malloc(sizeof(SDL_Rect));
	*g_Graph->info.cicle_to_die = *g_Graph->info.cicles_gen;
	g_Graph->info.processos = (SDL_Rect *)malloc(sizeof(SDL_Rect));
	*g_Graph->info.processos = *g_Graph->info.cicles_gen;
}

void			ft_ini_material(SDL_Surface *info_marc)
{
	unsigned int i;

	ini_info_rects();
	ini_number(GENERAL_NBR_FONT, &g_Graph->general_nbr,
		*(g_Graph->info.cicles_gen));
	ft_put_general_info();
	if (!(g_Graph->info.cicles_play = (SDL_Rect *)malloc(sizeof(SDL_Rect) *
		g_n_players)))
		ft_error("malloc ft_ini_material");
	if (!(g_Graph->info.lst_life = (SDL_Rect *)malloc(sizeof(SDL_Rect) *
		g_n_players)))
		ft_error("malloc 2 ft_ini_material");
	ini_number(PLAYER_NBR_FONT, &g_Graph->player_nbr,
			(SDL_Rect){0, 0, info_marc->w / 30, info_marc->h / 6});
	i = 0;
	while (i < g_n_players)
	{
		g_Graph->info.cicles_play[i] = (SDL_Rect){0, 0, info_marc->w / 30,
				info_marc->h / 6};
		g_Graph->info.lst_life[i] = (SDL_Rect){0, 0, info_marc->w / 30,
				info_marc->h / 6};
		ft_put_player_info(info_marc, i++);
	}
}

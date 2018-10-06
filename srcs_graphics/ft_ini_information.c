/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_information.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 03:49:02 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/06 04:05:20 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void		prepare_board_marc(void)
{
	SDL_Surface *marc_s;

	if (!(marc_s = SDL_CreateRGBSurfaceWithFormat(0, (g_graph->square->w - 1)
		* g_graph->cuant_squares[0] + 6, (g_graph->square->h - 1) *
		g_graph->cuant_squares[1] + 6, 32, 372645892)))
		ft_sdl_error("SDL_CreateRGBSurfaceWithFormat", MODE_SDL);
	if (SDL_FillRect(marc_s, NULL, SDL_MapRGBA(marc_s->format, 120, 115,
		119, 255)) || SDL_FillRect(marc_s,
		&(SDL_Rect){3, 3, marc_s->w - 6, marc_s->h - 6}, 0))
		ft_sdl_error("SDL_FillRect", MODE_SDL);
	if (!(g_graph->marc_board = SDL_CreateTextureFromSurface(
		g_graph->screen.renderer, marc_s)))
		ft_sdl_error("SDL_CreateTextureFromSurface", MODE_SDL);
	SDL_FreeSurface(marc_s);
}

static void		prepare_ends(SDL_Surface *info_marc)
{
	SDL_Surface *marc;
	Uint32		color[2];
	int			i;

	i = -1;
	color[0] = SDL_MapRGBA(info_marc->format, 0x5E, 0x5E, 0x5E, 127);
	color[1] = SDL_MapRGBA(info_marc->format, 0xFF, 0xFF, 0x33, 127);
	while (++i < 2)
	{
		if (!(marc = SDL_CreateRGBSurfaceWithFormat(0, info_marc->w,
			info_marc->h, 32, 372645892)))
			ft_sdl_error("SDL_CreateRGBSurfaceWithFormat", MODE_SDL);
		if (SDL_FillRect(marc, NULL, color[i]))
			ft_sdl_error("SDL_FillRect", MODE_SDL);
		if (!(g_graph->end[i] = SDL_CreateTextureFromSurface(
			g_graph->screen.renderer, marc)))
			ft_sdl_error("SDL_CreateTextureFromSurface", MODE_SDL);
		if (SDL_SetTextureBlendMode(g_graph->end[0], SDL_BLENDMODE_BLEND))
			ft_sdl_error("SDL_SetTextureBlendMode", MODE_SDL);
		SDL_FreeSurface(marc);
	}
}

void			ft_ini_information(void)
{
	SDL_Surface *info_marc;

	if (!(g_graph->square_info = (SDL_Rect *)malloc(sizeof(SDL_Rect))))
		ft_error("ft_memalloc ft_ini_information");
	g_graph->square_info->w = g_graph->screen.w * LEFT_BORDER -
		g_graph->screen.w * RIGHT_BORDER;
	g_graph->square_info->h = g_graph->big_square->h / 4;
	if (!(g_graph->info_text = SDL_CreateTexture(g_graph->screen.renderer,
		372645892, SDL_TEXTUREACCESS_STREAMING, g_graph->square_info->w,
		g_graph->big_square->h)))
		ft_sdl_error("SDL_CreateTexture", MODE_SDL);
	if (!(info_marc = SDL_CreateRGBSurfaceWithFormat(0, g_graph->square_info->w,
		(g_graph->big_square->h - g_graph->square_info->h) / 4, 32, 372645892)))
		ft_sdl_error("SDL_CreateRGBSurfaceWithFormat", MODE_SDL);
	prepare_ends(info_marc);
	ft_ini_material(info_marc);
	if (!(g_graph->info_marc = (SDL_Rect *)ft_memalloc(sizeof(SDL_Rect))))
		ft_error("malloc ft_ini_information 2");
	*g_graph->info_marc = (SDL_Rect){g_graph->screen.w * RIGHT_BORDER +
		g_graph->big_square->w + 20, g_graph->square_info->h + 10,
		info_marc->w, info_marc->h};
	SDL_FreeSurface(info_marc);
	prepare_board_marc();
}

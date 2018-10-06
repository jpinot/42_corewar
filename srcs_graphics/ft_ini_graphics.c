/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_graphics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 05:20:16 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/06 04:07:21 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void				ini_graph(void)
{
	if (!(g_graph = (t_sdl *)ft_memalloc(sizeof(t_sdl))))
		ft_error("Error malloc ft_ini_graphics\n");
	g_graph->screen.w = SCREEN_W;
	g_graph->screen.h = SCREEN_H;
	g_graph->screen.name = SCREEN_NAME;
}

static void				prepare_all(void)
{
	ft_ini_interface();
	ft_ini_font();
	ft_ini_information();
	ft_ini_pcs();
	ft_ini_images();
	ft_ini_sprites(g_graph->info.cicles_play, g_graph->info_marc,
		g_graph->player_nbr);
}

void					ft_ini_graphics(const unsigned int flags)
{
	int imgflags;

	ini_graph();
	if (SDL_Init(SDL_INIT_EVERYTHING))
		ft_sdl_error("SDL_Init", MODE_SDL);
	if (TTF_Init())
		ft_sdl_error("SDL_Init", MODE_TTF);
	imgflags = IMG_INIT_JPG;
	if (!(IMG_Init(imgflags) & imgflags))
		ft_sdl_error("IMG_Init", MODE_IMG);
	if (!(g_graph->screen.window = SDL_CreateWindow(g_graph->screen.name,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, g_graph->screen.w,
			g_graph->screen.h, SDL_WINDOW_RESIZABLE)))
		ft_sdl_error("SDL_CreateWindow", MODE_SDL);
	if ((flags & 0x2) && SDL_SetWindowFullscreen(g_graph->screen.window,
			SDL_WINDOW_FULLSCREEN_DESKTOP))
		ft_sdl_error("SDL_SetWindowFullscreen", MODE_SDL);
	SDL_GetWindowSize(g_graph->screen.window, &(g_graph->screen.w),
			&(g_graph->screen.h));
	if (!(g_graph->screen.renderer = SDL_CreateRenderer(g_graph->screen.window,
			-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		ft_sdl_error("SDL_CreateRenderer", MODE_SDL);
	if (SDL_SetRenderDrawColor(g_graph->screen.renderer, 0, 0, 0, 0))
		ft_sdl_error("SDL_SetRenderDrawColor", MODE_SDL);
	prepare_all();
}

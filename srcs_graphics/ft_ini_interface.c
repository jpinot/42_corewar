/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 06:40:13 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/30 21:53:39 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void					ini_big_rack(void)
{
	int square_dim[2];

	g_Graph->cuant_squares[0] = 64;
	g_Graph->cuant_squares[1] = (MEM_SIZE / 64 + (MEM_SIZE % 64 ? 1 : 0));
	square_dim[0] = 0;
	square_dim[1] = 0;
	while (square_dim[0] * g_Graph->cuant_squares[0] <= g_Graph->screen.w -
			(g_Graph->screen.w * LEFT_BORDER) -
			(g_Graph->screen.w * RIGHT_BORDER))
		square_dim[0]++;
	while (square_dim[1] * g_Graph->cuant_squares[1] <= g_Graph->screen.h -
			(g_Graph->screen.h * UPPER_BORDER) -
			(g_Graph->screen.h * BOTTOM_BORDER))
		square_dim[1]++;
	g_Graph->square = &(SDL_Rect){g_Graph->screen.w * RIGHT_BORDER + 1,
			g_Graph->screen.h * UPPER_BORDER + 1, square_dim[0],
			square_dim[1]};
}

static void					ini_rack(void)
{
	int			square_dim[2];

	square_dim[0] = 0;
	square_dim[1] = 0;
	g_Graph->cuant_squares[0] = 64;
	g_Graph->cuant_squares[1] = 64;
	while (square_dim[0] * 64 <= g_Graph->screen.w - (g_Graph->screen.w *
			LEFT_BORDER) - (g_Graph->screen.w * RIGHT_BORDER))
		square_dim[0]++;
	while (square_dim[1] * 64 <= g_Graph->screen.h - (g_Graph->screen.h *
			UPPER_BORDER) - (g_Graph->screen.h * BOTTOM_BORDER))
		square_dim[1]++;
	if (!(g_Graph->square = (SDL_Rect *)malloc(sizeof(SDL_Rect))))
		ft_error("Error malloc ini_rack\n");
	g_Graph->square->x = 0;
	g_Graph->square->y = 0;
	g_Graph->square->w = square_dim[0];
	g_Graph->square->h = square_dim[1];
}

/*
**Para dump hay que hacer que el textur blend y el alpha mod no se activen
**cuando se use el modo dump
*/

static void					prepare_big_square(void)
{
	if (!(g_Graph->big_square = (SDL_Rect *)malloc(sizeof(SDL_Rect))))
		ft_error("Error malloc ft_ini_interface\n");
	g_Graph->big_square->x = g_Graph->screen.w * RIGHT_BORDER;
	g_Graph->big_square->y = g_Graph->screen.h * UPPER_BORDER;
	g_Graph->big_square->w = g_Graph->screen.w *
			(1 - RIGHT_BORDER - LEFT_BORDER);
	g_Graph->big_square->h = g_Graph->screen.h *
			(1 - UPPER_BORDER - BOTTOM_BORDER);
}

void						ft_ini_interface(void)
{
	int i;

	i = MAX_PLAYERS;
	prepare_big_square();
	if (!(g_Graph->rack = SDL_CreateRGBSurfaceWithFormat(0,
			g_Graph->big_square->w, g_Graph->big_square->h, 32, 372645892)))
		ft_sdl_error("SDL_CreateRGBSurface", MODE_SDL);
	if (MEM_SIZE <= 4096)
		ini_rack();
	else
		ini_big_rack();
	if (!(g_Graph->screen.texture = SDL_CreateTexture(g_Graph->screen.Renderer,
			372645892, SDL_TEXTUREACCESS_STREAMING, g_Graph->big_square->w,
			g_Graph->big_square->h)))
		ft_sdl_error("SDL_CreateTexture", MODE_SDL);
	if (!(g_Graph->pc = (SDL_Texture **)malloc(sizeof(SDL_Texture *) * i * 4)))
		ft_error("Error malloc ft_ini_interface\n");
	ft_ini_pcs();
	if (SDL_SetTextureBlendMode(g_Graph->screen.texture, SDL_BLENDMODE_BLEND))
		ft_sdl_error("SDL_SetTextureBlendMode", MODE_SDL);
	if (SDL_SetTextureAlphaMod(g_Graph->screen.texture, 100))
		ft_sdl_error("SDL_SetTextureAlphaMod", MODE_SDL);
}

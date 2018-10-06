/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_pcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:57:43 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/06 04:05:19 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void			paint_pc(int *pixel, int pitch, SDL_Rect pc, Uint32 color)
{
	int		i;
	int		j;

	i = 0;
	while (i < pc.h)
	{
		j = 0;
		while (j < pc.w)
			pixel[i * pitch / 4 + j++] = color;
		i++;
	}
}

void				ft_ini_pcs(void)
{
	int			i;
	SDL_Rect	pc;
	int			*pixel;
	int			pitch;
	Uint32		color;

	i = MAX_PLAYERS;
	if (!(g_graph->pc = (SDL_Texture **)malloc(sizeof(SDL_Texture *) * i * 4)))
		ft_error("Error malloc ft_ini_interface\n");
	pc = (SDL_Rect){0, 0, g_graph->square->w - 2, g_graph->square->h - 2};
	i = -1;
	while (++i < MAX_PLAYERS * 4)
	{
		color = ft_maprgba(g_graph->general_nbr->format, i, 1);
		if (!(g_graph->pc[i] = SDL_CreateTexture(g_graph->screen.renderer,
				372645892, SDL_TEXTUREACCESS_STREAMING, g_graph->square->w - 2,
				g_graph->square->h - 2)))
			ft_sdl_error("SDL_CreateTexture", MODE_SDL);
		if (SDL_SetTextureBlendMode(g_graph->pc[i], SDL_BLENDMODE_BLEND))
			ft_sdl_error("SDL_SetTextureBlendMode", MODE_SDL);
		if (SDL_LockTexture(g_graph->pc[i], &pc, (void **)&pixel, &pitch))
			ft_sdl_error("SDL_LockTexture", MODE_SDL);
		paint_pc(pixel, pitch, pc, color);
		SDL_UnlockTexture(g_graph->pc[i]);
	}
}

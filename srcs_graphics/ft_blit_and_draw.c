/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blit_and_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 22:37:56 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/06 00:39:45 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	ft_blit_and_draw(SDL_Surface *hall)
{
	if (SDL_BlitSurface(g_graph->pause[1], NULL, hall, &(SDL_Rect){0, 0,
		g_graph->pause[0]->w, g_graph->pause[0]->h}))
		ft_sdl_error("SDL_BlitSurface", MODE_SDL);
	if (SDL_BlitSurface(g_graph->little_screen, NULL, hall, &(SDL_Rect){(hall->w
		- g_graph->little_screen->w) / 2, (hall->h - g_graph->little_screen->h)
		/ 4, g_graph->little_screen->w, g_graph->little_screen->h}))
		ft_sdl_error("SDL_BlitSurface", MODE_SDL);
	if (SDL_BlitSurface(g_graph->plus_minus[0], NULL, hall, &(SDL_Rect){(hall->w
		- g_graph->little_screen->w) / 2, (hall->h - g_graph->little_screen->h)
		/ 4 + g_graph->little_screen->h, g_graph->little_screen->w,
		g_graph->little_screen->h}))
		ft_sdl_error("SDL_BlitSurface", MODE_SDL);
	if (SDL_BlitSurface(g_graph->plus_minus[2], NULL, hall, &(SDL_Rect){(hall->w
		- g_graph->little_screen->w) / 2 + g_graph->button_pos->w,
		(hall->h - g_graph->little_screen->h) / 4 + g_graph->little_screen->h,
		g_graph->little_screen->w, g_graph->little_screen->h}))
		ft_sdl_error("SDL_BlitSurface", MODE_SDL);
	ft_surf_to_text(g_graph->info_text, hall,
		&(SDL_Rect){g_graph->square_info->w - hall->w, 0,
		hall->w, g_graph->big_square->h});
	SDL_FreeSurface(hall);
}

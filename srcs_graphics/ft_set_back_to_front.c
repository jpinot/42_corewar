/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_back_to_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:19:40 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/06 04:08:42 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static SDL_Rect		prepare_rect(void)
{
	return ((SDL_Rect){g_graph->info_marc->x, g_graph->square_info->h +
		g_graph->screen.h * UPPER_BORDER, g_graph->info_marc->w -
		(g_graph->square_info->w - g_graph->player_nbr->w * 21),
		g_graph->info_marc->h});
}

static int			put_end_frame(void)
{
	int			i;
	SDL_Rect	pos;

	i = -1;
	pos = prepare_rect();
	while (++i < g_n_players)
	{
		if (SDL_SetRenderDrawBlendMode(g_graph->screen.renderer,
				SDL_BLENDMODE_BLEND))
			ft_sdl_error("SDL_SetRenderDrawBlendMode", MODE_SDL);
		if (i == g_winner && SDL_RenderCopy(g_graph->screen.renderer,
			g_graph->end[1], NULL, &pos))
			ft_sdl_error("SDL_RenderCopy", MODE_SDL);
		else if (SDL_RenderCopy(g_graph->screen.renderer, g_graph->end[0],
			NULL, &pos))
			ft_sdl_error("SDL_RenderCopy", MODE_SDL);
		if (SDL_SetRenderDrawBlendMode(g_graph->screen.renderer,
			SDL_BLENDMODE_NONE))
			ft_sdl_error("SDL_SetRenderDrawBlendMode", MODE_SDL);
		pos.y += pos.h;
	}
	return (1);
}

void				ft_set_back_to_front(void)
{
	SDL_Renderer	*renderer;
	static int		end = 0;

	if (end)
		return ;
	renderer = g_graph->screen.renderer;
	ft_pcs_to_rack(g_frame->nb_pc, g_frame->pcs, 0);
	if (SDL_RenderCopy(renderer, g_graph->marc_board, NULL,
		&(SDL_Rect){g_graph->big_square->x - 3, g_graph->big_square->y - 3,
		(g_graph->square->w - 1) * g_graph->cuant_squares[0] + 6,
		(g_graph->square->h - 1) * g_graph->cuant_squares[1] + 6}))
		ft_sdl_error("SDL_RenderCopy", MODE_SDL);
	if (SDL_RenderCopy(renderer, g_graph->info_text, NULL,
		&(SDL_Rect){g_graph->screen.w * RIGHT_BORDER + g_graph->big_square->w
		+ 20, g_graph->screen.h * UPPER_BORDER, g_graph->square_info->w,
		g_graph->big_square->h}))
		ft_sdl_error("SDL_RenderCopy", MODE_SDL);
	if (g_frame->prog_end)
		end = put_end_frame();
	SDL_RenderPresent(renderer);
	if (SDL_SetRenderDrawColor(g_graph->screen.renderer, 0, 0, 0, 255))
		ft_sdl_error("SDL_SetRenderDrawColor", MODE_SDL);
	if (!g_frame->prog_end)
		if (SDL_RenderClear(renderer))
			ft_sdl_error("SDL_RenderClear", MODE_SDL);
}

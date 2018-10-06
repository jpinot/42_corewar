/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pcs_to_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 07:37:31 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/06 04:05:19 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	ft_pcs_to_rack(const unsigned int nb_pc,
		const unsigned int *pcs, int stela)
{
	unsigned int	j;
	SDL_Rect		pc_rect;

	pc_rect = (SDL_Rect){0, 0, g_graph->square->w - 2, g_graph->square->h - 2};
	j = -1;
	while (++j < nb_pc)
	{
		pc_rect.x = g_graph->screen.w * RIGHT_BORDER + (g_graph->square->w - 1)
			* ((pcs[j] & 0xFFFFFF) % g_graph->cuant_squares[0]) + 1;
		pc_rect.y = g_graph->screen.h * UPPER_BORDER + (g_graph->square->h - 1)
			* ((pcs[j] & 0xFFFFFF) / g_graph->cuant_squares[1]) + 1;
		if (SDL_RenderCopy(g_graph->screen.renderer,
			g_graph->pc[((pcs[j] & 0xFF000000) >> 24) + 8
			+ MAX_PLAYERS * stela], NULL, &pc_rect))
			ft_sdl_error("SDL_RenderCopy", MODE_SDL);
	}
}

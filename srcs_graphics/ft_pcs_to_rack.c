/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pcs_to_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 07:37:31 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/24 22:36:12 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	ft_pcs_to_rack(const unsigned int nb_pc, const unsigned int *pcs, const unsigned int flags, int stela)
{
	unsigned int j;
	SDL_Rect	pc_rect;

	pc_rect = (SDL_Rect){0, 0, g_Graph->square->w - 2, g_Graph->square->h - 2};
	j = -1;
	while (++j < nb_pc)
	{
		pc_rect.x = g_Graph->screen.w * RIGHT_BORDER + (g_Graph->square->w - 1)
			* ((pcs[j] & 0xFFFFFF) % g_Graph->cuant_squares[0]) + 2;
		pc_rect.y = g_Graph->screen.h * UPPER_BORDER + (g_Graph->square->h - 1)
			* ((pcs[j] & 0xFFFFFF) / g_Graph->cuant_squares[1]) + 1;
		SDL_RenderCopy(g_Graph->screen.Renderer,
		               g_Graph->pc[((pcs[j] & 0xFF000000) >> 24) + 8 - (flags & 0x4) * 8 +
			MAX_PLAYERS * stela], NULL, &pc_rect);
	}
}

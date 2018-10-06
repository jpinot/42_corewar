/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 06:40:13 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/04 05:31:36 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void					ini_big_rack(void)
{
	int square_dim[2];

	g_graph->cuant_squares[0] = 64;
	g_graph->cuant_squares[1] = (MEM_SIZE / 64 + (MEM_SIZE % 64 ? 1 : 0));
	square_dim[0] = 0;
	square_dim[1] = 0;
	while (square_dim[0] * g_graph->cuant_squares[0] <= g_graph->big_square->w)
		square_dim[0]++;
	while (square_dim[1] * g_graph->cuant_squares[1] <= g_graph->big_square->h)
		square_dim[1]++;
	g_graph->square = &(SDL_Rect){g_graph->screen.w * RIGHT_BORDER + 1,
			g_graph->screen.h * UPPER_BORDER + 1, square_dim[0],
			square_dim[1]};
}

static void					ini_rack(void)
{
	int			square_dim[2];

	square_dim[0] = 0;
	square_dim[1] = 0;
	g_graph->cuant_squares[0] = 64;
	g_graph->cuant_squares[1] = 64;
	while ((square_dim[0]) * 64 < g_graph->big_square->w)
		square_dim[0]++;
	while ((square_dim[1]) * 64 < g_graph->big_square->h)
		square_dim[1]++;
	if (!(g_graph->square = (SDL_Rect *)malloc(sizeof(SDL_Rect))))
		ft_error("Error malloc ini_rack\n");
	g_graph->square->x = 0;
	g_graph->square->y = 0;
	g_graph->square->w = square_dim[0];
	g_graph->square->h = square_dim[1];
}

static void					prepare_big_square(void)
{
	if (!(g_graph->big_square = (SDL_Rect *)malloc(sizeof(SDL_Rect))))
		ft_error("Error malloc ft_ini_interface\n");
	g_graph->big_square->x = g_graph->screen.w * RIGHT_BORDER;
	g_graph->big_square->y = g_graph->screen.h * UPPER_BORDER;
	g_graph->big_square->w = g_graph->screen.w *
			(1 - RIGHT_BORDER - LEFT_BORDER);
	g_graph->big_square->h = g_graph->screen.h *
			(1 - UPPER_BORDER - BOTTOM_BORDER);
}

void						ft_ini_interface(void)
{
	prepare_big_square();
	if (MEM_SIZE <= 4096)
		ini_rack();
	else
		ini_big_rack();
}

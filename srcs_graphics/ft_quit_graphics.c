/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 05:27:44 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/06 04:08:17 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void		destroy_hex_array(SDL_Texture ***hex_array)
{
	int i;
	int j;
	int k;

	k = 0;
	while (k < 9)
	{
		i = 0;
		while (i < 16)
		{
			j = 0;
			while (j < 16)
			{
				SDL_DestroyTexture(hex_array[k][i * 16 + j]);
				j++;
			}
			i++;
		}
		free(hex_array[k]);
		SDL_DestroyTexture(hex_array[9][k]);
		k++;
	}
	free(hex_array[9]);
	free(hex_array);
}

static void		destroy_rects(t_info info)
{
	free(info.cicles_gen);
	free(info.cicles_play);
	free(info.lst_life);
	free(info.cicle_to_die);
	free(info.processos);
	free(g_graph->heart_pos);
	free(g_graph->square);
	free(g_graph->big_square);
	free(g_graph->square_info);
	free(g_graph->info_marc);
	free(g_graph->button_pos);
	free(g_graph->little_screen_pos);
}

static void		destroy_surfaces(void)
{
	int i;

	i = 0;
	destroy_hex_array(g_graph->hexa_bytes);
	SDL_FreeSurface(g_graph->general_nbr);
	SDL_FreeSurface(g_graph->player_nbr);
	SDL_FreeSurface(g_graph->pause[0]);
	SDL_FreeSurface(g_graph->pause[1]);
	while (i < 7)
		SDL_FreeSurface(g_graph->heart[i++]);
	free(g_graph->heart);
	i = 0;
	while (i < 4)
		SDL_FreeSurface(g_graph->plus_minus[i++]);
	SDL_FreeSurface(g_graph->little_screen);
}

static void		destroy_pcs(void)
{
	int i;

	i = 0;
	while (i < MAX_PLAYERS * 4)
		SDL_DestroyTexture(g_graph->pc[i++]);
}

void			ft_quit_graphics(void)
{
	int i;

	destroy_rects(g_graph->info);
	destroy_surfaces();
	destroy_pcs();
	SDL_DestroyTexture(g_graph->info_text);
	i = 0;
	while (i < MAX_PLAYERS * 4)
		SDL_DestroyTexture(g_graph->pc[i++]);
	free(g_graph->pc);
	SDL_DestroyRenderer(g_graph->screen.renderer);
	SDL_DestroyWindow(g_graph->screen.window);
	i = 0;
	while (i < 4)
		TTF_CloseFont(g_graph->font[i++].font);
	TTF_Quit();
	SDL_Quit();
	free(g_graph);
}

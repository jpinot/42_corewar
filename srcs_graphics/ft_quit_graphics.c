/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit_graphics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 05:27:44 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/30 22:19:53 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void		destroy_hex_array(SDL_Surface ***hex_array)
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
				SDL_FreeSurface(hex_array[k][i * 16 + j]);
				j++;
			}
			i++;
		}
		free(hex_array[k]);
		SDL_FreeSurface(hex_array[9][k]);
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
	free(g_Graph->heart_pos);
	free(g_Graph->square);
	free(g_Graph->big_square);
	free(g_Graph->square_info);
	free(g_Graph->info_marc);
}

static void		destroy_surfaces(void)
{
	int i;

	i = 0;
	destroy_hex_array(g_Graph->hexa_bytes);
	SDL_FreeSurface(g_Graph->rack);
	SDL_FreeSurface(g_Graph->general_nbr);
	SDL_FreeSurface(g_Graph->player_nbr);
	SDL_FreeSurface(g_Graph->pause[0]);
	SDL_FreeSurface(g_Graph->pause[1]);
	while (i < 7)
		SDL_FreeSurface(g_Graph->heart[i++]);
	free(g_Graph->heart);
}

void			ft_quit_graphics(void)
{
	int i;

	destroy_rects(g_Graph->info);
	destroy_surfaces();
	SDL_DestroyTexture(g_Graph->screen.texture);
	SDL_DestroyTexture(g_Graph->info_text);
	i = 0;
	while (i < MAX_PLAYERS * 4)
		SDL_DestroyTexture(g_Graph->pc[i++]);
	free(g_Graph->pc);
	SDL_DestroyRenderer(g_Graph->screen.Renderer);
	SDL_DestroyWindow(g_Graph->screen.window);
	i = 0;
	while (i < 4)
		TTF_CloseFont(g_Graph->font[i++].font);
	TTF_Quit();
	SDL_Quit();
	free(g_Graph);
}

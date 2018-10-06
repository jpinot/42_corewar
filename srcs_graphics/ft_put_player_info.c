/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_player_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 10:18:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/01 19:50:26 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static int		prepare_string(int pos[2], char *str, int mode)
{
	SDL_Surface *tmp_surf;
	int			tmp;

	tmp_surf = ft_write_string(str, pos, mode);
	tmp = tmp_surf->h;
	SDL_FreeSurface(tmp_surf);
	return (tmp);
}

void			ft_put_player_info(SDL_Surface *info_marc, int i)
{
	int				tmp;
	int				y_pos;
	int				tmp2;

	tmp = 10;
	g_graph->font[TMP_FONT].color = ft_sdl_color(i);
	g_graph->font[PLAYER_NBR_FONT].color = g_graph->font[TMP_FONT].color;
	y_pos = g_graph->square_info->h + 10 + info_marc->h * i;
	y_pos += prepare_string((int[2]){tmp, y_pos}, g_players[i].name, 0) + 20;
	tmp2 = prepare_string((int[2]){tmp + (g_graph->player_nbr->w * 10 - 9)
			/ 2, y_pos }, "Number of Lifes", 1);
	ft_write_number_fields(&g_graph->font[PLAYER_NBR_FONT],
			(int[2]){tmp, y_pos + tmp2}, g_graph->player_nbr);
	g_graph->info.cicles_play[i] = (SDL_Rect){tmp, y_pos + tmp2,
			g_graph->info.cicles_play[i].w, g_graph->info.cicles_play[i].h};
	tmp += g_graph->player_nbr->w * 10 - 9 + 20;
	tmp2 = prepare_string((int[2]){tmp + (g_graph->player_nbr->w * 10 - 9)
			/ 2, y_pos}, "Last Life", 1);
	ft_write_number_fields(&g_graph->font[PLAYER_NBR_FONT],
			(int[2]){tmp, y_pos + tmp2}, g_graph->player_nbr);
	g_graph->info.lst_life[i] = (SDL_Rect){tmp, y_pos + tmp2,
			g_graph->info.lst_life[i].w, g_graph->info.lst_life[i].h};
}

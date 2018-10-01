/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_general_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 10:20:06 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/28 18:10:43 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void		prepare_font(int nbr_font, SDL_Color color)
{
	t_font	*font;
	t_font	*ref_font;

	font = &(g_Graph->font[nbr_font]);
	ref_font = &(g_Graph->font[FIELD_FONT]);
	font->font_size = ref_font->font_size * 2;
	font->font = TTF_OpenFont("./whitrabt.ttf", font->font_size);
	TTF_SizeUTF8(font->font, "A", &font->w, &font->h);
	font->color = color;
}

static int		prepare_string(int pos[2], char *str, int mode)
{
	SDL_Surface *tmp_surf;
	int			tmp;

	tmp_surf = ft_write_string(str, pos, mode);
	tmp = tmp_surf->h;
	SDL_FreeSurface(tmp_surf);
	return (tmp);
}

void			ft_put_general_info(void)
{
	int			tmp;
	int			x_pos;

	prepare_font(TMP_FONT, (SDL_Color){255, 255, 255, 255});
	x_pos = 50;
	g_Graph->font[GENERAL_NBR_FONT].color = g_Graph->font[TMP_FONT].color;
	tmp = 15;
	tmp += prepare_string((int[2]){x_pos + (g_Graph->general_nbr->w * 10 - 9)
			/ 2, tmp}, "Number of Cycles", 1);
	*g_Graph->info.cicles_gen = (SDL_Rect){x_pos, tmp,
			g_Graph->info.cicles_gen->w, g_Graph->info.cicles_gen->h};
	tmp += ft_write_number_fields(&g_Graph->font[GENERAL_NBR_FONT],
			(int[2]){x_pos, tmp}, g_Graph->general_nbr) + 10;
	tmp += prepare_string((int[2]){x_pos + (g_Graph->general_nbr->w * 10 - 9)
			/ 2, tmp}, "Cycles to Die", 1);
	*g_Graph->info.cicle_to_die = (SDL_Rect){x_pos, tmp,
			g_Graph->info.cicles_gen->w, g_Graph->info.cicles_gen->h};
	tmp += ft_write_number_fields(&g_Graph->font[GENERAL_NBR_FONT],
			(int[2]){x_pos, tmp}, g_Graph->general_nbr) + 10;
	tmp += prepare_string((int[2]){x_pos + (g_Graph->general_nbr->w * 10 - 9)
			/ 2, tmp}, "Number of Processos", 1);
	*g_Graph->info.processos = (SDL_Rect){x_pos, tmp,
			g_Graph->info.cicles_gen->w, g_Graph->info.cicles_gen->h};
	tmp += ft_write_number_fields(&g_Graph->font[GENERAL_NBR_FONT],
			(int[2]){x_pos, tmp}, g_Graph->general_nbr);
}

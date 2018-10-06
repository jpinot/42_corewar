/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:53:11 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/05 23:30:07 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void			ft_update_little_screen(void)
{
	SDL_Surface	*tmp;
	t_font		font;
	SDL_Surface *num_surf;
	char		*digit;

	if (!(digit = ft_itoa(g_cycle_cuant)))
		ft_error("ft_itoa update_little_screen");
	if (!(num_surf = SDL_CreateRGBSurfaceWithFormat(0,
		g_graph->little_screen->w, g_graph->little_screen->h, 32, 372645892)))
		ft_sdl_error("SDL_CreateRGBSurfaceWithFormat", MODE_SDL);
	if (SDL_BlitSurface(g_graph->little_screen, NULL, num_surf, NULL))
		ft_sdl_error("SDL_BlitSurface", MODE_SDL);
	font = g_graph->font[GENERAL_NBR_FONT];
	if (!(tmp = TTF_RenderUTF8_Blended(font.font, digit, font.color)))
		ft_sdl_error("TTF_RenderUTF8_Blended", MODE_TTF);
	if (SDL_BlitSurface(tmp, NULL, num_surf, &(SDL_Rect){(num_surf->w -
		tmp->w) / 2, (num_surf->h - tmp->h) / 2, tmp->w, tmp->h}))
		ft_sdl_error("SDL_BlitSurface", MODE_SDL);
	ft_surf_to_text(g_graph->info_text, num_surf, g_graph->little_screen_pos);
	SDL_FreeSurface(tmp);
	SDL_FreeSurface(num_surf);
	free(digit);
}

void			ft_back_forw_buttons(int mode)
{
	if (mode == 1)
	{
		g_cycle_cuant = (g_cycle_cuant == 1) ? 1 : g_cycle_cuant - 1;
		ft_surf_to_text2(g_graph->info_text, g_graph->plus_minus[1],
		g_graph->button_pos);
	}
	else if (mode == 2)
	{
		g_cycle_cuant++;
		ft_surf_to_text2(g_graph->info_text, g_graph->plus_minus[3],
			&(SDL_Rect) {g_graph->button_pos->x + g_graph->button_pos->w,
			g_graph->button_pos->y, g_graph->button_pos->w,
			g_graph->button_pos->h});
	}
	else if (mode == -1)
		ft_surf_to_text2(g_graph->info_text, g_graph->plus_minus[0],
			g_graph->button_pos);
	else if (mode == -2)
		ft_surf_to_text2(g_graph->info_text, g_graph->plus_minus[2],
			&(SDL_Rect){g_graph->button_pos->x + g_graph->button_pos->w,
			g_graph->button_pos->y, g_graph->button_pos->w,
			g_graph->button_pos->h});
	ft_update_little_screen();
}

int				ft_pause_button(unsigned int pause)
{
	SDL_Surface *button;
	int			hall_dim;

	hall_dim = g_graph->square_info->w - g_graph->player_nbr->w * 21;
	if (pause)
		button = g_graph->pause[0];
	else
		button = g_graph->pause[1];
	ft_surf_to_text2(g_graph->info_text, button, &(SDL_Rect)
		{g_graph->square_info->w - g_graph->pause[0]->w, 0,
		g_graph->pause[0]->w, g_graph->pause[0]->h});
	return (pause ? 0 : 0x1);
}

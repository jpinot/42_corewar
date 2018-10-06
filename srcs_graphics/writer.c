/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 18:42:52 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/06 00:32:02 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

SDL_Surface			*ft_write_string(char *str, int pos[2], int name)
{
	SDL_Surface *str_surf;
	SDL_Surface *tmp;

	if (!(tmp = TTF_RenderUTF8_Blended(g_graph->font[TMP_FONT].font, str,
		g_graph->font[TMP_FONT].color)))
		ft_sdl_error("TTF_RenderUTF8_Blended", MODE_TTF);
	if (!(str_surf = SDL_CreateRGBSurfaceWithFormat(0, tmp->w, tmp->h, 32,
		372645892)))
		ft_sdl_error("SDL_CreateRGBSurfaceWithFormat", MODE_SDL);
	if (SDL_BlitSurface(tmp, NULL, str_surf, NULL))
		ft_sdl_error("SDL_BlitSurface", MODE_SDL);
	SDL_FreeSurface(tmp);
	ft_surf_to_text(g_graph->info_text, str_surf,
		&(SDL_Rect){ft_abs(pos[0] - str_surf->w / 2 * name), pos[1],
		str_surf->w, str_surf->h});
	return (str_surf);
}

static void			place_fields(SDL_Rect *number_rect, SDL_Surface *number)
{
	char	*pixel;
	int		pitch;
	int		i[2];

	if (SDL_LockTexture(g_graph->info_text, number_rect,
		(void **)&pixel, &pitch))
		ft_sdl_error("SDL_LockTexture", MODE_SDL);
	if (SDL_LockSurface(number))
		ft_sdl_error("SDL_LockSurface", MODE_SDL);
	i[0] = 0;
	while (i[0] < 10)
	{
		i[1] = -1;
		while (++i[1] < number->h)
			ft_memcpy(pixel + i[0] * (number->pitch - 4) + i[1] *
			pitch, number->pixels + i[1] * number->pitch, number->pitch);
		i[0]++;
	}
	SDL_UnlockSurface(number);
	SDL_UnlockTexture(g_graph->info_text);
}

int					ft_write_number_fields(t_font *font, int pos[2],
		SDL_Surface *number)
{
	SDL_Surface *tmp;

	if (!(tmp = TTF_RenderUTF8_Blended(font->font, "0", font->color)))
		ft_sdl_error("TTF_RenderUTF8_Blended", MODE_TTF);
	if (SDL_FillRect(number, &(SDL_Rect){1, 1, number->w - 2, number->h - 2},
		SDL_MapRGBA(number->format, 0, 0, 0, 255)))
		ft_sdl_error("SDL_FillRect", MODE_SDL);
	if (SDL_BlitSurface(tmp, NULL, number, &(SDL_Rect){(number->w - tmp->w) / 2,
		(number->h - tmp->h) / 2 + 2, tmp->w, tmp->h}))
		ft_sdl_error("SDL_BlitSurface", MODE_SDL);
	place_fields(&(SDL_Rect){pos[0], pos[1], number->w * 10, number->h},
		number);
	SDL_FreeSurface(tmp);
	return (number->h);
}

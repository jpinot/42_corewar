/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:09:42 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/06 04:05:20 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void				insert_hexa_surf(char pair[3], int index[3])
{
	SDL_Surface *rack_square;
	SDL_Surface *tmp;

	if (!(rack_square = SDL_CreateRGBSurfaceWithFormat(0, g_graph->square->w,
		g_graph->square->h, 32, 372645892)))
		ft_sdl_error("SDL_CreateRGBSurfaceWithFormat", MODE_SDL);
	if (SDL_FillRect(rack_square, NULL, ft_maprgba(rack_square->format, 4, 0))
		|| SDL_FillRect(rack_square, &(SDL_Rect){1, 1, rack_square->w - 2,
		rack_square->h - 2}, ft_maprgba(rack_square->format, 5, 0)))
		ft_sdl_error("SDL_FillRect", MODE_SDL);
	if (!(tmp = TTF_RenderUTF8_Blended(g_graph->font[0].font, pair,
			ft_sdl_color(index[2]))))
		ft_sdl_error("TTF_RenderUTF8_Blended", MODE_TTF);
	if (SDL_BlitSurface(tmp, NULL, rack_square,
		&(SDL_Rect){(rack_square->w - tmp->w) / 2,
		(rack_square->h - tmp->h) / 2,
		tmp->w, tmp->h}))
		ft_sdl_error("SDL_BlitSurface", MODE_SDL);
	if (!(g_graph->hexa_bytes[index[2]][index[0] * 16 + index[1]] =
		SDL_CreateTextureFromSurface(g_graph->screen.renderer, rack_square)))
		ft_sdl_error("SDL_CreateTextureFromSurface", MODE_SDL);
	SDL_FreeSurface(tmp);
	SDL_FreeSurface(rack_square);
}

static void				generate_noinfo_squares(void)
{
	SDL_Surface *rack_square;
	int			i;
	SDL_Color	c;

	i = 0;
	if (!(g_graph->hexa_bytes[9] =
		(SDL_Texture **)ft_memalloc(sizeof(SDL_Texture *) * 9)))
		ft_error("ft_memalloc generate_hexadecimals");
	while (i < 9)
	{
		c = ft_sdl_color(i);
		if (!(rack_square = SDL_CreateRGBSurfaceWithFormat(0,
			g_graph->square->w, g_graph->square->h, 32, 372645892)))
			ft_sdl_error("SDL_CreateRGBSurfaceWithFormat", MODE_SDL);
		if (SDL_FillRect(rack_square, NULL, ft_maprgba(rack_square->format,
			4, 0)) || SDL_FillRect(rack_square, &(SDL_Rect){1, 1,
			rack_square->w - 2, rack_square->h - 2},
			SDL_MapRGBA(rack_square->format, c.r, c.g, c.b, c.a)))
			ft_sdl_error("SDL_FillRect", MODE_SDL);
		if (!(g_graph->hexa_bytes[9][i++] =
			SDL_CreateTextureFromSurface(g_graph->screen.renderer,
			rack_square)))
			ft_sdl_error("SDL_CreateTextureFromSurface", MODE_SDL);
		SDL_FreeSurface(rack_square);
	}
}

static void				generate_hexadecimals(void)
{
	int		i[3];
	char	hexa_characters[3];

	hexa_characters[2] = 0;
	i[0] = -1;
	while (++i[0] < 9)
	{
		i[1] = -1;
		if (!(g_graph->hexa_bytes[i[0]] =
			(SDL_Texture **)malloc(sizeof(SDL_Texture *) * 16 * 16)))
			ft_error("malloc 2 generate_hexadecimals");
		while (++i[1] < 16)
		{
			hexa_characters[0] = (i[1] >= 10 ? 'A' + i[1] - 10 : '0' + i[1]);
			i[2] = -1;
			while (++i[2] < 16)
			{
				hexa_characters[1] = (i[2] >= 10 ? 'A' + i[2] - 10 : 48 + i[2]);
				insert_hexa_surf(hexa_characters, (int[3]){i[1], i[2], i[0]});
			}
		}
	}
	generate_noinfo_squares();
}

void					ft_ini_font(void)
{
	g_graph->font[0].font_size = 1;
	while (g_graph->font[0].w + 5 < g_graph->square->w && g_graph->font[0].h + 5
			< g_graph->square->h)
	{
		if (g_graph->font[0].font)
			TTF_CloseFont(g_graph->font[0].font);
		if (!(g_graph->font[0].font =
				TTF_OpenFont("./whitrabt.ttf", g_graph->font[0].font_size++)))
			ft_sdl_error("TTF_OpenFont", MODE_TTF);
		if (TTF_SizeUTF8(g_graph->font[0].font, "FF", &g_graph->font[0].w,
			&g_graph->font[0].h))
			ft_sdl_error("TTF_SizeUTF8", MODE_TTF);
	}
	if (!(g_graph->hexa_bytes =
		(SDL_Texture ***)malloc(sizeof(SDL_Texture **) * 10)))
		ft_error("malloc generate_hexadecimals");
	generate_hexadecimals();
}

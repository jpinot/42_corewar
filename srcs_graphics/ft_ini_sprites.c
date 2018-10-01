/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:28:52 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/30 21:53:39 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void			prepare_all_sprites(int dim, SDL_Surface *sprite,
		SDL_Surface **ini_heart, SDL_Rect *info_marc)
{
	int			i;
	int			pos;
	SDL_Rect	pos_in_sprite;

	i = -1;
	pos = 1;
	pos_in_sprite = (SDL_Rect){2, 1, 76, 69};
	while (++i < 6)
	{
		if (!(pos % 2))
		{
			pos_in_sprite.y += 73;
			pos_in_sprite.x -= 80;
		}
		else
			pos_in_sprite.x += 80;
		if (!(ini_heart[pos] = SDL_CreateRGBSurfaceWithFormat(0, dim + 7,
			dim, 32, 372645892)))
			ft_sdl_error("SDL_CreateRGBSurfaceWithFormat", MODE_SDL);
		if (SDL_BlitScaled(sprite, &pos_in_sprite, ini_heart[pos++], NULL))
			ft_sdl_error("SDL_BlitScaled", MODE_SDL);
	}
	i = -1;
	while (++i < g_n_players)
		ft_reset_health(i, g_Graph->heart_pos, info_marc, ini_heart[0]);
}

static int			calc_sprite_size(SDL_Surface **ini_heart, int disp_space[2],
		SDL_Surface *sprite)
{
	int i;

	i = 1;
	while (!ini_heart[0] || (disp_space[1] - ini_heart[0]->h > 20
			&& ini_heart[0]->h < disp_space[1] && disp_space[0] >
			ini_heart[0]->w * 4))
	{
		if (ini_heart[0])
			SDL_FreeSurface(ini_heart[0]);
		if (!(ini_heart[0] = SDL_CreateRGBSurfaceWithFormat(0, i + 7, i,
			32, 372645892)))
			ft_sdl_error("SDL_CreateRGBSurfaceWithFormat", MODE_SDL);
		if (SDL_FillRect(ini_heart[0], NULL, 0xFF00FF00))
			ft_sdl_error("SDL_FillRect", MODE_SDL);
		if (SDL_BlitScaled(sprite, &(SDL_Rect){2, 1, 76, 69},
			ini_heart[0], NULL))
			ft_sdl_error("SDL_BlitScaled", MODE_SDL);
		i++;
	}
	return (i - 1);
}

static SDL_Surface	*open_sprite(void)
{
	SDL_Surface *sprite;
	SDL_RWops	*tmp;

	if (!(tmp = SDL_RWFromFile("./heart.png", "rb")))
		ft_sdl_error("SDL_RWFromFile", MODE_SDL);
	if (!(sprite = IMG_LoadPNG_RW(tmp)))
		ft_sdl_error("IMG_LoadPNG_RW", MODE_IMG);
	if (SDL_RWclose(tmp))
		ft_sdl_error("SDL_RWclose", MODE_SDL);
	return (sprite);
}

void				ft_ini_sprites(SDL_Rect *cicles_play,
		SDL_Rect *info_marc, SDL_Surface *player_nbr)
{
	SDL_Surface		*sprite;
	int				sprite_size;
	SDL_Surface		**ini_heart;

	if (!(ini_heart = (SDL_Surface **)ft_memalloc(sizeof(SDL_Surface *) * 7)))
		ft_error("malloc ft_ini_sprites");
	if (!(g_Graph->heart_pos = (SDL_Rect *)malloc(sizeof(SDL_Rect))))
		ft_error("malloc ft_ini_sprites 2");
	sprite = open_sprite();
	sprite_size = calc_sprite_size(ini_heart, (int[2]){player_nbr->w * 20,
		(info_marc->h - ((cicles_play[0].y + cicles_play[0].h) -
		(info_marc->y)))}, sprite);
	SDL_FreeSurface(ini_heart[0]);
	if (!(ini_heart[0] = SDL_CreateRGBSurfaceWithFormat(0, sprite_size + 7,
		sprite_size, 32, 372645892)))
		ft_sdl_error("SDL_CreateRGBSurfaceWithFormat", MODE_SDL);
	if (SDL_BlitScaled(sprite, &(SDL_Rect){2, 1, 76, 69},
		ini_heart[0], NULL))
		ft_sdl_error("SDL_BlitScaled", MODE_SDL);
	*g_Graph->heart_pos = (SDL_Rect){cicles_play[0].x, ((info_marc->h -
			((cicles_play[0].y + cicles_play[0].h) - (info_marc->y))) -
			ini_heart[0]->h) / 2 + cicles_play[0].y + cicles_play[0].h,
			ini_heart[0]->w, ini_heart[0]->h};
	prepare_all_sprites(sprite_size, sprite, ini_heart, info_marc);
	g_Graph->heart = ini_heart;
}

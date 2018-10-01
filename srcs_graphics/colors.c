/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 21:47:26 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/30 21:47:27 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static Uint32	take_rgba2(int id, SDL_PixelFormat *format)
{
	if (id == 8)
		return (SDL_MapRGBA(format, PLAYER_ONE_COLORC / 2));
	else if (id == 9)
		return (SDL_MapRGBA(format, PLAYER_TWO_COLORC / 2));
	else if (id == 10)
		return (SDL_MapRGBA(format, PLAYER_THREE_COLORC / 2));
	else if (id == 11)
		return (SDL_MapRGBA(format, PLAYER_FOUR_COLORC / 2));
	else if (id == 12)
		return (SDL_MapRGBA(format, PLAYER_ONE_COLORC / 2 + 20));
	else if (id == 13)
		return (SDL_MapRGBA(format, PLAYER_TWO_COLORC / 2 + 20));
	else if (id == 14)
		return (SDL_MapRGBA(format, PLAYER_THREE_COLORC / 2 + 20));
	else
		return (SDL_MapRGBA(format, PLAYER_FOUR_COLORC / 2 + 20));
}

static Uint32	take_rgba(int id, SDL_PixelFormat *format)
{
	if (!id)
		return (SDL_MapRGBA(format, PLAYER_ONE_COLORA / 2));
	else if (id == 1)
		return (SDL_MapRGBA(format, PLAYER_TWO_COLORA / 2));
	else if (id == 2)
		return (SDL_MapRGBA(format, PLAYER_THREE_COLORA / 2));
	else if (id == 3)
		return (SDL_MapRGBA(format, PLAYER_FOUR_COLORA / 2));
	else if (id == 4)
		return (SDL_MapRGBA(format, PLAYER_ONE_COLORA / 2 + 20));
	else if (id == 5)
		return (SDL_MapRGBA(format, PLAYER_TWO_COLORA / 2 + 20));
	else if (id == 6)
		return (SDL_MapRGBA(format, PLAYER_THREE_COLORA / 2 + 20));
	else if (id == 7)
		return (SDL_MapRGBA(format, PLAYER_FOUR_COLORA / 2 + 20));
	else
		return (take_rgba2(id, format));
}

static Uint32	take_rgb(int i, SDL_PixelFormat *format)
{
	if (!i)
		return (SDL_MapRGBA(format, PLAYER_ONE_COLORA));
	else if (i == 1)
		return (SDL_MapRGBA(format, PLAYER_TWO_COLORA));
	else if (i == 2)
		return (SDL_MapRGBA(format, PLAYER_THREE_COLORA));
	else if (i == 3)
		return (SDL_MapRGBA(format, PLAYER_FOUR_COLORA));
	else if (i == 4)
		return (SDL_MapRGBA(format, FIELD_COLOR));
	else
		return (SDL_MapRGBA(format, BACK_COLOR));
}

SDL_Color		ft_sdl_color(int i)
{
	if (i == 0)
		return ((SDL_Color){PLAYER_ONE_COLORA});
	else if (i == 1)
		return ((SDL_Color){PLAYER_TWO_COLORA});
	else if (i == 2)
		return ((SDL_Color){PLAYER_THREE_COLORA});
	else if (i == 3)
		return ((SDL_Color){PLAYER_FOUR_COLORA});
	else if (i == 4)
		return ((SDL_Color){NONE_COLOR});
	else if (i == 5)
		return ((SDL_Color){PLAYER_ONE_COLORB});
	else if (i == 6)
		return ((SDL_Color){PLAYER_TWO_COLORB});
	else if (i == 7)
		return ((SDL_Color){PLAYER_THREE_COLORB});
	else
		return ((SDL_Color){PLAYER_FOUR_COLORB});
}

Uint32			ft_maprgba(SDL_PixelFormat *format, int i, int alpha)
{
	if (!alpha)
		return (take_rgb(i, format));
	else
		return (take_rgba(i, format));
}

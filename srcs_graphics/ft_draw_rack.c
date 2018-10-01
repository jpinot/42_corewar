/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 14:15:37 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/24 22:07:06 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void		ft_draw_rack(t_data *data)
{
	SDL_Surface *rack;
	char	*pixel;
	int		pitch;

		rack = data->arena->Graph->rack;
		SDL_LockTexture(data->arena->Graph->screen.texture, NULL, (void **)&pixel, &pitch);
	SDL_LockSurface(rack);
//	i = -1;
//	while (++i < rack->h)
	for (int j = 0; j < rack->h; j++)
		ft_memcpy(pixel + j * pitch, rack->pixels + j * rack->pitch,
			rack->pitch);
	SDL_UnlockSurface(rack);
	SDL_UnlockTexture(data->arena->Graph->screen.texture);
	/* rack = data->arena->Graph->rack; */
	/* SDL_LockTexture(data->arena->Graph->screen.texture, NULL, (void **)&pixel, &pitch); */
	/* SDL_LockSurface(rack); */
	/* for(int j = 0; j < rack->h; j++) */
	/* 	memcpy(pixel + j * pitch, rack->pixels + j * rack->pitch, rack->pitch); */
	/* SDL_UnlockSurface(rack); */
	/* SDL_UnlockTexture(data->arena->Graph->screen.texture); */
}

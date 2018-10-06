/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_surf_to_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:18:47 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/05 19:00:02 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	ft_surf_to_text2(SDL_Texture *dst, SDL_Surface *src, SDL_Rect *dst_rect)
{
	int		*pixel;
	int		pitch;
	int		i[3];

	if (SDL_LockTexture(dst, dst_rect, (void **)&pixel, &pitch))
		ft_sdl_error("SDL_LockTexture", MODE_SDL);
	if (SDL_LockSurface(src))
		ft_sdl_error("SDL_LockSurface", MODE_SDL);
	i[0] = -1;
	i[1] = 0;
	i[2] = 0;
	while (++(i[0]) < src->h)
	{
		i[1] = i[0] * pitch / sizeof(int);
		while (i[2] < (int)((src->pitch / sizeof(int)) * i[0]))
		{
			if (((int *)src->pixels)[i[2]])
				pixel[i[1]] = ((int *)src->pixels)[i[2]];
			(i[2])++;
			(i[1])++;
		}
	}
	SDL_UnlockSurface(src);
	SDL_UnlockTexture(dst);
}

void	ft_surf_to_text(SDL_Texture *dst, SDL_Surface *src, SDL_Rect *dst_rect)
{
	char	*pixel;
	int		pitch;
	int		j;

	if (SDL_LockTexture(dst, dst_rect, (void **)&pixel, &pitch))
		ft_sdl_error("SDL_LockTexture", MODE_SDL);
	if (SDL_LockSurface(src))
		ft_sdl_error("SDL_LockSurface", MODE_SDL);
	j = -1;
	while (++j < src->h)
		ft_memcpy(pixel + j * pitch, src->pixels + j * src->pitch, src->pitch);
	SDL_UnlockSurface(src);
	SDL_UnlockTexture(dst);
}

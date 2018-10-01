/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_surf_to_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:18:47 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/30 22:13:12 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	ft_surf_to_text(SDL_Texture *dst, SDL_Surface *src, SDL_Rect *dst_rect)
{
	char	*pixel;
	int		pitch;
	int		j;

	if (SDL_LockTexture(dst, dst_rect, (void **)&pixel, &pitch))
		ft_sdl_error("SDL_LockTexture", MODE_SDL);
	if (SDL_LockSurface(src))
		ft_sdl_error("SDL_LockSurface", MODE_SDL);
	j = 0;
	while (++j < src->h)
		memcpy(pixel + j * pitch, src->pixels + j * src->pitch, src->pitch);
	SDL_UnlockSurface(src);
	SDL_UnlockTexture(dst);
}

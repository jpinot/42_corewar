/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 05:14:24 by jagarcia          #+#    #+#             */
/*   Updated: 2018/09/30 21:51:18 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	ft_sdl_error(char *str, int mode)
{
	char *tmp;

	tmp = ft_strjoin(str, ": %s\n");
	if (mode > 0)
		ft_printf(tmp, SDL_GetError());
	else if (!mode)
		ft_printf(tmp, TTF_GetError());
	else
		ft_printf(tmp, IMG_GetError());
	free(tmp);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_health.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 23:04:22 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/01 19:50:26 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	ft_reset_health(int player, SDL_Rect *heart_pos, SDL_Rect *info_marc,
		SDL_Surface *ini_heart)
{
	int i;
	int dist;

	dist = (g_graph->player_nbr->w * 20 - heart_pos->w * 4) / 3 + heart_pos->w;
	i = 0;
	while (i < 4)
		ft_surf_to_text(g_graph->info_text, ini_heart,
		&(SDL_Rect){heart_pos->x + dist * i++, heart_pos->y + (info_marc->h) *
		player, ini_heart->w, ini_heart->h});
}

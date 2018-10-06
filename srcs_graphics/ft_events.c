/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:43:28 by jagarcia          #+#    #+#             */
/*   Updated: 2018/10/05 23:31:46 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void		mouse_event(SDL_Event e, int mode)
{
	if (SDL_PointInRect(&(SDL_Point){e.button.x, e.button.y},
		&(SDL_Rect){g_graph->button_pos->x + g_graph->screen.w *
		RIGHT_BORDER + g_graph->big_square->w + 20, g_graph->button_pos->y
		+ g_graph->screen.h * UPPER_BORDER, g_graph->button_pos->w,
		g_graph->button_pos->h}))
		ft_back_forw_buttons(1 * mode);
	else if (SDL_PointInRect(&(SDL_Point){e.button.x, e.button.y},
		&(SDL_Rect){g_graph->button_pos->x + g_graph->button_pos->w +
		g_graph->screen.w * RIGHT_BORDER + g_graph->big_square->w + 20,
		g_graph->button_pos->y + g_graph->screen.h * UPPER_BORDER,
		g_graph->button_pos->w, g_graph->button_pos->h}))
		ft_back_forw_buttons(2 * mode);
}

static void		keyup_event(SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_KP_PLUS)
		ft_back_forw_buttons(-2);
	else if (event.key.keysym.sym == SDLK_KP_MINUS)
		ft_back_forw_buttons(-1);
}

static void		keydown_event(SDL_Event event, int *running)
{
	if (event.key.keysym.sym == SDLK_ESCAPE)
		*running = SDL_FALSE;
	else if (event.key.keysym.sym == SDLK_SPACE)
		g_pause = ft_pause_button(g_pause);
	else if (event.key.keysym.sym == SDLK_RIGHT)
		g_step = 1;
	else if (event.key.keysym.sym == SDLK_i)
		g_hexl = g_hexl ? 0 : 1;
	else if (event.key.keysym.sym == SDLK_KP_PLUS)
		ft_back_forw_buttons(2);
	else if (event.key.keysym.sym == SDLK_KP_MINUS)
		ft_back_forw_buttons(1);
}

void			ft_events(int *running)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			*running = SDL_FALSE;
		else if (event.type == SDL_KEYDOWN)
			keydown_event(event, running);
		else if (event.type == SDL_KEYUP)
			keyup_event(event);
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
				mouse_event(event, 1);
		}
		else if (event.type == SDL_MOUSEBUTTONUP)
			if (event.button.button == SDL_BUTTON_LEFT)
				mouse_event(event, -1);
	}
}

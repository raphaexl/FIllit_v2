/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 00:19:34 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/25 17:07:59 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

void		ft_update_event(t_input *input)
{
	SDL_Event	event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			input->quit = SDL_TRUE;
		if (event.type == SDL_KEYDOWN)
			input->key[event.key.keysym.scancode] = SDL_TRUE;
		if (event.type == SDL_KEYUP)
			input->key[event.key.keysym.scancode] = SDL_FALSE;
		if (event.type == SDL_MOUSEBUTTONUP)
			input->mouse[event.button.button] = SDL_FALSE;
		if (event.type == SDL_MOUSEBUTTONDOWN)
			input->mouse[event.button.button] = SDL_TRUE;
		if (event.type == SDL_MOUSEMOTION)
		{
			input->mousex = event.motion.x;
			input->mousey = event.motion.y;
			input->mousexrel = event.motion.xrel;
			input->mouseyrel = event.motion.yrel;
		}
		if (event.type == SDL_MOUSEWHEEL)
		{
			input->xwheel = event.wheel.x;
			input->ywheel = event.wheel.y;
		}
	}
}

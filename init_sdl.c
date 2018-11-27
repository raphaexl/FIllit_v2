/* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:20:58 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/27 07:25:37 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

SDL_Window	*window;
SDL_Renderer	*renderer;


SDL_Window	*ft_get_window(void)
{
	return (window);
}

SDL_Color	ft_get_color(char	c)
{
	SDL_Color	color;
		if (c == 'A')
	{
		color.r = 255;
		color.g = 0;
		color.b = 0;
		color.a = 255;
	return (color);
	}
	if (c == 'B')
	{
		color.r = 0;
		color.g = 255;
		color.b = 0;
		color.a = 255;
	return (color);
	}
	if (c == 'C')
	{
		color.r = 0;
		color.g = 0;
		color.b = 255;
		color.a = 255;
	return (color);
	}
	if (c == 'D')
	{
		color.r = 230;
		color.g = 126;
		color.b = 48;
		color.a = 255;
	return (color);
	}
	if (c == 'E')
	{
		color.r = 121;
		color.g = 248;
		color.b = 248;
		color.a = 255;
	return (color);
	}
	if (c == 'F')
	{
		color.r = 240;
		color.g = 195;
		color.b = 0;
		color.a = 255;
	return (color);
	}if (c == 'G')
	{
		color.r = 192;
		color.g = 192;
		color.b = 192;
		color.a = 255;
	return (color);
	}
	if (c == 'H')
	{
		color.r = 136;
		color.g = 77;
		color.b = 167;
		color.a = 255;
	return (color);
	}

	if (c == 'I')
	{
		color.r = 139;
		color.g = 108;
		color.b = 66;
		color.a = 255;
	return (color);
	}
	if (c == 'J')
	{
		color.r = 255;
		color.g = 203;
		color.b = 96;
		color.a = 255;
	return (color);
	}
	if (c == 'K')
	{
		color.r = 255;
		color.g = 228;
		color.b = 196;
		color.a = 255;
	return (color);
	}
	if (c == 'L')
	{
		color.r = 254;
		color.g = 254;
		color.b = 254;
		color.a = 255;
	return (color);
	}
	if (c == 'M')
	{
		color.r = 58;
		color.g = 142;
		color.b = 186;
		color.a = 255;
	return (color);
	}
	if (c == 'N')
	{
		color.r = 84;
		color.g = 114;
		color.b = 174;
		color.a = 255;
	return (color);
	}
	if (c == 'O')
	{
		color.r = 38;
		color.g = 196;
		color.b = 236;
		color.a = 255;
	return (color);
	}
	if (c == 'P')
	{
		color.r = 44;
		color.g = 117;
		color.b = 255;
		color.a = 255;
	return (color);
	}



	if (c == 'Q')
	{
		color.r = 27;
		color.g = 1;
		color.b = 155;
		color.a = 255;
	return (color);
	}

	if (c == 'R')
	{
		color.r = 255;
		color.g = 94;
		color.b = 77;
		color.a = 255;
	return (color);
	}
	if (c == 'S')
	{
		color.r = 31;
		color.g = 160;
		color.b = 85;
		color.a = 255;
	return (color);
	}

	if (c == 'T')
	{
		color.r = 190;
		color.g = 245;
		color.b = 116;
		color.a = 255;
	return (color);
	}
	if (c == 'U')
	{
		color.r = 38;
		color.g = 97;
		color.b = 156;
		color.a = 255;
	return (color);
	}
	if (c == 'V')
	{
		color.r = 108;
		color.g = 2;
		color.b = 119;
		color.a = 255;
	return (color);
	}if (c == 'W')
	{
		color.r = 165;
		color.g = 209;
		color.b = 82;
		color.a = 255;
	return (color);
	}if (c == 'X')
	{
		color.r = 114;
		color.g = 62;
		color.b = 100;
		color.a = 255;
	return (color);
	}if (c == 'Y')
	{
		color.r = 176;
		color.g = 242;
		color.b = 82;
		color.a = 255;
	return (color);
	}

	if (c == 'Z')
	{
		color.r = 37;
		color.g = 253;
		color.b = 253;
		color.a = 255;
	return (color);
	}
	else 
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
		color.a = 255;
	return (color);
	}
}

SDL_Renderer *ft_get_renderer(void)
{
	return (renderer);
}

int		ft_init_sdl(void)
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		fprintf(stderr,"Error SDL_Init() %s", SDL_GetError());
		return (-1);
	}
	if (!(window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_SHOWN)))
	{
		fprintf(stderr, "Error SDL_CreateWindow %s", SDL_GetError());
		return (-1);
	}
	if (!(renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
	{
		fprintf(stderr, "Error SDL_CreateRenderer() %s", SDL_GetError());
		return (-1);
	}
	return (0);
}

void	ft_draw_sdl(char (*board)[MAX_SIZE])
{
	int		i;
	int		j;
	SDL_Surface *surf;

	i = 0;
	surf = SDL_CreateRGBSurface(0, 90, 90, 32, 0, 0, 0, 0);
	SDL_RenderClear(ft_get_renderer());
	while (board[i][0] != '0')
	{
		j = 0;
		while (board[i][j] != '0')
		{
			SDL_Rect rect = { 15 + j*100,  15 +i*100, 90, 90};
			SDL_Color col;
			col = ft_get_color(board[i][j]);
			SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, 0xff);
			SDL_RenderFillRect(renderer, &rect);
			j++;
		}
		i++;
	}
	SDL_SetWindowSize(ft_get_window(),  i * 105, i * 105); 
	SDL_SetRenderDrawColor(ft_get_renderer(), 0, 0, 0, 255);
	SDL_RenderPresent(ft_get_renderer());
	SDL_Delay(10);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 03:09:00 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/25 20:26:07 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

char		**ft_check_validity(char **av)
{
	char	temp[BUFF_SIZE + 1];
	char	**tab;
	int		n;
	int		fd;

	tab = NULL;
	fd = open(av[1], O_RDONLY);
	n = read(fd, temp, BUFF_SIZE);
	if (n <= 0 || n >= 545)
		ft_error();
	temp[n] = '\0';
	if (!ft_check_linesep(temp))
		ft_error();
	ft_only_nhd(temp);
	if (!(tab = ft_strsplit(temp, '*')))
		ft_error();
	if (!ft_last_check(tab))
		ft_error();
	return (tab);
}

int			ft_last_check(char **tab)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (tab[i])
	{
		k = 0;
		while (tab[i][k] && tab[i][k] != '#')
			k++;
		if (tab[i][k] == '#')
			ft_side_connection(tab[i], k);
		if (!ft_check_no_hash(tab[i]))
			ft_error();
		i++;
	}
	return (1);
}

int		ft_init_fillit(char	(*board)[MAX_SIZE], char **argv, t_tetriminos **t)
{
	char	**tab;
	int		i;
	int		size;

	tab = NULL;
	i = 0;
	size = 0;
	if ((tab = ft_check_validity(argv)))
	{
		while (tab[i])
		{
			ft_push_back_tetriminos(t, ft_create_tetriminos(tab[i], i));
			i++;
		}
		ft_init_board(board, size = ft_sqrt(i * 4));
	}
	return (size);
}

void	ft_raz_tab(char (*board)[MAX_SIZE])
{
	int		i = -1;
	int		j = -1;

	while (++i < MAX_SIZE && (j = -1))
		while (++j < MAX_SIZE)
			board[i][j] = '0';
	ft_putendl("Called");
}

int		ft_fillit(char **argv)
{
	char	board[MAX_SIZE][MAX_SIZE];
	t_tetriminos *t;
	int		size = 0;
	t_input	input;
	Uint32  ticks;
	Uint32  ticks_t;


	t = NULL;
	memset(&input, SDL_FALSE, sizeof(t_input)); 
	ft_raz_tab(board);
	size = ft_init_fillit(board, argv, &t);
	ft_init_sdl();
	ticks = SDL_GetTicks();
	ft_solve_tetriminos(board, t, size);
	while (!input.quit)
	{	
		ft_update_event(&input);
		ticks_t = SDL_GetTicks();
		if (ticks_t - ticks > 100)
		{
		   	ft_draw_sdl(board);
			ticks = ticks_t;
		}
		else
			SDL_Delay(100 - (ticks_t - ticks));
		SDL_Delay(1000);
	}
	ft_free_tetriminos(&t);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 02:44:25 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/26 20:22:25 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

void		ft_init_board(char (*board)[MAX_SIZE], int size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < size && (j = -1))
		while (++j < size)
			board[i][j] = '.';
}

int			ft_place_tetriminos(char (*board)[MAX_SIZE], t_tetriminos *t, int y, int x)
{
	int		i = -1;

	while (++i < 4)
		if (board[y + t->tab[i].y][x + t->tab[i].x] != '.')
			return (0);
	/*board[y + t->tab[0].y][x + t->tab[0].x] = t->name;
	board[y + t->tab[1].y][x + t->tab[1].x] = t->name;
	board[y + t->tab[2].y][x + t->tab[2].x] = t->name;
	board[y + t->tab[3].y][x + t->tab[3].x] = t->name;*/
	i = -1;
	while (++i < 4)
		board[y + t->tab[i].y][x + t->tab[i].x] = t->name;
	return (1);
}

void		ft_delete_tetriminos(char (*board)[MAX_SIZE], t_tetriminos *t, int y, int x)
{
	int		i = -1;

	while (++i < 4)
		board[y + t->tab[i].y][x + t->tab[i].x] = '.';
	/*board[y + t->tab[0].y][x + t->tab[0].x] = '.';
	board[y + t->tab[1].y][x + t->tab[1].x] = '.';
	board[y + t->tab[2].y][x + t->tab[2].x] = '.';
	board[y + t->tab[3].y][x + t->tab[3].x] = '.';*/
}

int		ft_solve_tetriminos(char (*board)[MAX_SIZE], t_tetriminos *t, int size)
{
	int		i;
	int		j;

	i = -1;
	while (board[++i][0] != '0' && (j = -1))
	{
		while (board[i][++j] != '0')
		{
			ft_draw_sdl(board);
			SDL_Delay(10);
			if (ft_place_tetriminos(board, t, i, j))
			{
				if (!t->next)
					return (1);
				else if (ft_solve_tetriminos(board, t->next, size))
					return (1);
				else
					ft_delete_tetriminos(board, t, i, j);
			}
		}
	}
	if (t && t->name == 'A')
	{
		ft_init_board(board, size + 1);
		ft_solve_tetriminos(board, t, size + 1);
	}
	return (0);
}

void	ft_print_board(char (*board)[MAX_SIZE])
{
	int		i;
	int		j;

	i = -1;
	while (board[++i][0] != '0' && (j = -1))
	{
		while (board[i][++j] != '0')
			ft_putchar(board[i][j]);
		ft_putchar('\n');
	}
}

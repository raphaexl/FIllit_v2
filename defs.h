/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 00:40:29 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/25 17:04:26 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_mixer.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>

# define BUFF_SIZE 550
# define MAX_SIZE 20
# define SCR_WIDTH 800
# define SCR_HEIGHT 800

typedef struct		s_input
{
	int			mousex;
	int			mousey;
	int			mousexrel;
	int			mouseyrel;
	int			xwheel;
	int			ywheel;
	SDL_bool    key[SDL_NUM_SCANCODES];
	SDL_bool	quit;
	SDL_bool	mouse[6];
}					t_input;

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_tetrim
{
	char			name;
	//SDL_Texture		*img;
	//SDL_Rect		pos;
	t_point			tab[4];
	struct s_tetrim	*next;
}					t_tetriminos;

void				ft_update_event(t_input *input);
SDL_Window			*ft_get_window(void);
SDL_Renderer 		*ft_get_renderer(void);
int					ft_init_sdl(void);
void				ft_draw_sdl(char (*board)[MAX_SIZE]);

long long	int		ft_fabs(long long int n);
void				ft_putchar(char c);
void				ft_putendl(const char *str);
void				ft_putstr(const char *str);
void				ft_putnbr(long long int n);
int					ft_strns(char *str, int n);
int					ft_sqrt(int n);
void				ft_usage(void);
void				ft_error(void);
void				ft_display_tab(char **tab);
char				**ft_strsplit(char *str, char c);
int					ft_randint(int min, int max);;

int					ft_check_characters(char *content);
int					ft_check_no_hash(char *str);
int					ft_check_linesep(char *content);
void				ft_side_connection(char *str, int i);
int					ft_only_nhd(char *content);
char				**ft_check_validity(char **av);
int					ft_last_check(char **tab);
int					ft_init_fillit(char	(*board)[MAX_SIZE], char **argv, t_tetriminos **t);
int					ft_fillit(char **argv);
void				ft_print_board(char (*board)[MAX_SIZE]);

void				ft_init_board(char (*board)[MAX_SIZE], int size);
int					ft_place_tetriminos(char (*board)[MAX_SIZE], t_tetriminos *t, int x, int y);
void				ft_delete_tetriminos(char (*board)[MAX_SIZE], t_tetriminos *t, int x, int y);
int					ft_solve_tetriminos(char (*board)[MAX_SIZE], t_tetriminos *t, int size);

t_tetriminos		*ft_create_tetriminos(char *line, int index);
void				ft_draw_tetriminos(t_tetriminos		*t);
void				ft_push_front_tetriminos(t_tetriminos **t, t_tetriminos *n);
void				ft_push_back_tetriminos(t_tetriminos **t, t_tetriminos *n);
void				ft_pop_front_tetriminos(t_tetriminos **t);
void				ft_pop_back_tetriminos(t_tetriminos **t);
void				ft_free_tetriminos(t_tetriminos **t);
int					ft_tetriminos_len(t_tetriminos *t);
# endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 03:46:38 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/25 16:47:19 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "defs.h"

long long	int		ft_fabs(long long int n)
{
	return ((n > 0) ? (n) : (-n));
}
void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putendl(const char *str)
{
	if (str)
	{
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 1);
	}
	return ;
}

void		ft_putstr(const char *str)
{
	if (str)
	{
		while (*str)
			write(1, str++, 1);
	}
	return ;
}

void		ft_putnbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = ft_fabs(n);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n % 10 + '0');
}

int			ft_strns(char *s, int c)
{
	int		i;
	int		number;

	i = 0;
	number = 0;
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			number++;
		i++;
	}
	number = (s[i] != c) ? number + 1 : number;
	return (number);
}

int			ft_sqrt(int n)
{
	int		rac;

	rac = 0;
	if (n > 0)
	{
		rac = 1;
		while (rac * rac < n)
			rac++;
		rac = (rac * rac >= n) ? rac : rac + 1;
	}
	return (rac);
}

void		ft_usage(void)
{
	ft_putendl("usage: ./fillit file");
}

void		ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

void		ft_display_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_putstr(tab[i++]);
}

char		**ft_strsplit(char *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if ((tab = (char **)malloc(sizeof(char *) * (1 + ft_strns(str, c)))))
	{
		while (str[i] && k < ft_strns(str, c))
		{
			if ((tab[k] = (char *)malloc(255)))
			{
				j = 0;
				while (str[i] && str[i] != c)
					tab[k][j++] = str[i++];
				if (j)
					tab[k++][j] = '\0';
			}
			i++;
		}
		tab[k] = 0;
	}
	return (tab);
}

void		ft_print_tetriminos(t_tetriminos *t)
{
	t_tetriminos	*p;
	int				i;

	p = t;
	while (p)
	{
		i = 0;
		ft_putendl("There is ");
		while (i < 4)
		{
			ft_putchar(t->name);
			ft_putnbr(t->tab[i].x);
			ft_putchar(' ');
			ft_putnbr(t->tab[i].y);
			ft_putchar('\n');
			i++;
		}
		p = p->next;
	}
}

int		ft_randint(int min, int max)
{
	static SDL_bool initialized = SDL_FALSE;
	
	if (!initialized)
	{
		initialized = SDL_TRUE;
		srand(time(NULL));
	}
	return ((rand() % (max - min)));
}

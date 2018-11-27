/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 00:48:49 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/25 02:19:13 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

t_tetriminos		*ft_create_tetriminos(char *line, int index)
{
	t_tetriminos	*new;
	int				i;
	int				k;
	int				i_;

	if ((new = (t_tetriminos *)malloc(sizeof(t_tetriminos))))
	{
		i = 0;
		k = 0;
		while (line[i])
		{
			if (line[i] == '@')
			{
				i_ = k ? i_ : i;
				new->tab[k].x = (i % 5) - (i_ % 5);
				new->tab[k].y = (i / 5) - (i_ / 5);
				k++;
			}
			i++;
		}
		new->name = 'A' + index;
		//new->img = ft_get_appropriate_img(new->tab);
		new->next = NULL;
	}
	return (new);
}

void				ft_push_back_tetriminos(t_tetriminos **t, t_tetriminos *new)
{
	t_tetriminos	*p;

	if (!t || !new)
		return ;
	else if (!*t)
		*t = new;
	else
	{
		p = *t;
		while (p->next)
			p = p->next;
		if (p)
			p->next = new;
	}
}

void				ft_pop_front_tetriminos(t_tetriminos **t)
{
	t_tetriminos	*p;

	p = *t;
	if (p)
	{
		*t = (*t)->next;
		free(p);
		if (!*t)
			t = NULL;
	}

}

void				ft_push_front_tetriminos(t_tetriminos **t, t_tetriminos *new)
{
	if (!t || !new)
		return ;
	if (!*t)
		*t = new;
	else
		new->next = *t;
	*t = new;
}

void				ft_pop_back_tetriminos(t_tetriminos **t)
{
	t_tetriminos	*p;
	t_tetriminos 	*q;

	if (!t)
		return ;
	p = *t;
	while (p->next)
	{
		q = p;
		p = q;
	}
	if (p)
	{
		q->next = NULL;
		free(p);
	}
	if (!*t)
		free(t), t = NULL;
}

void				ft_free_tetriminos(t_tetriminos **t)
{
	t_tetriminos	*p;

	p = *t;
	while (p)
	{
		*t = (*t)->next;
		free(p);
		p = *t;
	}
	t = NULL;
}

int					ft_tetriminos_len(t_tetriminos *t)
{
	if (!t)
		return (0);
	else
		return (1 + ft_tetriminos_len(t->next));
}

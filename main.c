/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 00:19:16 by ebatchas          #+#    #+#             */
/*   Updated: 2018/11/24 03:48:08 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

int		main(int argc, char *argv[])
{
	if (argc != 2)
		ft_usage();
	else
		ft_fillit(argv);
	return (0);
}

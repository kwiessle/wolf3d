/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:30:01 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/24 16:20:13 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
//#include "../textures/plasma_maze.xpm"

int		main(int ac, char **av)
{
	t_map	*map;
	int		fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	map = get_map(fd);
	return (0);
}

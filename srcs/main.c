/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:30:01 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/28 12:53:27 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
//#include "../textures/plasma_maze.xpm"

int		main(int ac, char **av)
{
	t_env	*env;
	int		fd;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	env = init_env(fd);
	raycasting(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	mlx_hook(env->win, 2, 3, keyboard, env);
	mlx_loop(env->mlx);
	return (0);
}

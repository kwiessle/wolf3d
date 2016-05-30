/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:30:01 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/29 20:43:03 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
//#include "../textures/plasma_maze.xpm"

int		main(int ac, char **av)
{
	t_env	*env;
	int		fd;
	t_img	*menu;
	int		w;
	int		h;

	(void)ac;
	w = X_WIN;
	h = 200;
	if (!(menu = (t_img *)malloc(sizeof(t_img))))
		return (0);
	fd = open(av[1], O_RDONLY);
	env = init_env(fd);
	raycasting(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	menu->img = init_img(env);
	menu->img = mlx_xpm_file_to_image(env->mlx, "misc/menu.xpm", &w, &h);
	mlx_put_image_to_window(env->mlx, env->win, menu->img, 0, Y_WIN);
	mlx_hook(env->win, 2, 3, keyboard, env);
	mlx_loop(env->mlx);
	return (0);
}

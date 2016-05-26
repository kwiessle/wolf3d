/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 10:50:48 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/26 13:01:19 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		keyboard(int keycode, t_env *env)
{
	if (env->mlx == NULL)
		return (0);
	if (keycode == EXIT)
		exit(EXIT_SUCCESS);
	if (keycode == LEFT)
		rot_left(env);
	if (keycode == RIGHT)
		rot_right(env);
	if (keycode == UP || keycode == DOWN)
		moove(keycode, env);
	return (0);
}

void	expose(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img->img);
	e->img->img = mlx_new_image(e->mlx, X_WIN, Y_WIN);
	raycasting(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
}
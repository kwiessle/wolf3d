/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 11:27:02 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/26 14:18:18 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_env		*init_env(int fd)
{
	t_env		*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, X_WIN, Y_WIN, "Wolf3D");
	env->map = get_map(fd, env);
	env->img = init_img(env);
	env->posx = (double)env->xmax / 2;
	env->posy = (double)env->ymax / 2;
	printf("posX %f\n", env->posx);
	printf("posY %f\n", env->posy);
	env->dirx = -1;
	env->diry = 0;
	env->xmax = 0;
	env->ymax = 0;
	env->planex = 0;
	env->planey = 0.66;
	env->time = 0;
	env->oldtime = env->time;
	env->time = clock();
	env->fps = (env->time - env->oldtime) / 1000.0;
	env->movespeed = env->fps * 0.004;
	env->rotspeed = env->fps * 0.002;
	return (env);
}

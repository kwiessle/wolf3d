/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 11:27:02 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/27 13:43:40 by kwiessle         ###   ########.fr       */
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
	env->tab = (int *)mlx_get_data_addr(env->img->img, &env->img->bpp, &env->img->size_line, &env->img->endian);
	env->buffer = init_tab(env);
	env->texture = create_texture(env);
	return (env);
}

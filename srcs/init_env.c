/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 11:27:02 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/30 14:43:47 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		new_window(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, X_WIN, Y_WIN + 200, "Wolf3D");
	env->img = init_img(env);
}

t_env			*init_env(void)
{
	t_env		*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	new_window(e);
	e->music = 0;
	e->posx = 3;
	e->posy = 5;
	e->dirx = -1;
	e->diry = 0;
	e->xmax = 0;
	e->ymax = 0;
	e->planex = 0;
	e->planey = 0.66;
	e->time = 0;
	e->oldtime = e->time;
	e->time = clock();
	e->fps = (e->time - e->oldtime) / 1000.0;
	e->movespeed = e->fps * 0.001;
	e->rotspeed = e->fps * 0.0005;
	e->tab = (int *)mlx_get_data_addr(e->img->img, &e->img->bpp, \
			&e->img->size_line, &e->img->endian);
	e->buffer = init_tab(e);
	e->texture = create_texture(e);
	return (e);
}

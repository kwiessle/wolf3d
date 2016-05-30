/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 12:29:27 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/30 14:40:25 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_ray(t_env *env, int x)
{
	env->camx = 2 * x / (double)X_WIN - 1;
	env->rayposx = env->posx;
	env->rayposy = env->posy;
	env->raydirx = env->dirx + env->planex * env->camx;
	env->raydiry = env->diry + env->planey * env->camx;
	env->mapx = (int)env->rayposx;
	env->mapy = (int)env->rayposy;
	env->deltx = sqrt(1 + pow(env->raydiry, 2) / pow(env->raydirx, 2));
	env->delty = sqrt(1 + pow(env->raydirx, 2) / pow(env->raydiry, 2));
	env->hit = 0;
	env->stepx = (env->raydirx < 0) ? -1 : 1;
	if (env->stepx == -1)
		env->sidedirx = (env->rayposx - env->mapx) * env->deltx;
	else
		env->sidedirx = (env->mapx + 1.0 - env->rayposx) * env->deltx;
	env->stepy = (env->raydiry < 0) ? -1 : 1;
	if (env->stepy == -1)
		env->sidediry = (env->rayposy - env->mapy) * env->delty;
	else
		env->sidediry = (env->mapy + 1.0 - env->rayposy) * env->delty;
}

void		check_wall(t_env *env)
{
	while (env->hit == 0)
	{
		if (env->sidedirx < env->sidediry)
		{
			env->sidedirx += env->deltx;
			env->mapx += env->stepx;
			env->side = 0;
		}
		else
		{
			env->sidediry += env->delty;
			env->mapy += env->stepy;
			env->side = 1;
		}
		if (check_map(env->mapx, env->mapy) > 0)
			env->hit = 1;
	}
}

void		get_color(t_env *env)
{
	env->lineheight = (int)(Y_WIN / env->perpwalldist);
	env->drawstart = -env->lineheight / 2 + Y_WIN / 2;
	env->drawend = env->lineheight / 2 + Y_WIN / 2;
	if (env->drawstart < 0)
		env->drawstart = 0;
	if (env->drawend >= Y_WIN)
		env->drawend = Y_WIN;
	if (env->side == 1)
		env->wallx = env->rayposx + ((env->mapy - env->rayposy + \
					(1 - env->stepy) / 2) / env->raydiry) * env->raydirx;
	else
		env->wallx = env->rayposy + ((env->mapx - env->rayposx + \
					(1 - env->stepx) / 2) / env->raydirx) * env->raydiry;
	env->wallx -= floor(env->wallx);
	env->texx = (int)(env->wallx * 64);
	if (!env->side && env->raydirx > 0)
		env->texx = 64 - env->texx - 1;
	if (env->side && env->raydiry < 0)
		env->texx = 64 - env->texx - 1;
}

int			raycasting(t_env *env)
{
	int		x;
	double	color;

	x = 0;
	color = 0;
	while (x < X_WIN)
	{
		init_ray(env, x);
		check_wall(env);
		if (env->side == 0)
			env->perpwalldist = (env->mapx - env->rayposx + \
					(1 - env->stepx) / 2) / env->raydirx;
		else
			env->perpwalldist = (env->mapy - env->rayposy + \
					(1 - env->stepy) / 2) / env->raydiry;
		get_color(env);
		get_texture(x, env->drawstart, color, env);
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	return (0);
}

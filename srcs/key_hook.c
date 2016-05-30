/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:05:57 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/29 20:06:38 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		rot_left(t_env *e)
{
	double		olddirx;
	double		oldplanex;

	olddirx = e->dirx;
	e->dirx = e->dirx * cos(e->rotspeed) - e->diry * sin(e->rotspeed);
	e->diry = olddirx * sin(e->rotspeed) + e->diry * cos(e->rotspeed);
	oldplanex =e->planex;
	e->planex = e->planex * cos(e->rotspeed) - e->planey * sin(e->rotspeed);
	e->planey = oldplanex * sin(e->rotspeed) + e->planey * cos(e->rotspeed);
	expose(e);
}

void		rot_right(t_env *e)
{
	double		olddirx;
	double		oldplanex;

	olddirx = e->dirx;
	e->dirx = e->dirx * cos(-e->rotspeed) - e->diry * sin(-e->rotspeed);
	e->diry = olddirx * sin(-e->rotspeed) + e->diry * cos(-e->rotspeed);
	oldplanex =e->planex;
	e->planex = e->planex * cos(-e->rotspeed) - e->planey * sin(-e->rotspeed);
	e->planey = oldplanex * sin(-e->rotspeed) + e->planey * cos(-e->rotspeed);
	expose(e);
}

void		moove(int keycode, t_env *e)
{
	if (keycode == UP)
	{
		if (!check_map((int)(e->posx + e->dirx * e->movespeed), \
					(int)e->posy) && !check_map((int)e->posx, \
					(int)(e->posy + e->diry * e->movespeed)))
		{
			e->posx += e->dirx * e->movespeed;
			e->posy += e->diry * e->movespeed;
		}
		else
			ft_putchar('\a');
	}
	if (keycode == DOWN)
	{
		if (!check_map((int)(e->posx - e->dirx * e->movespeed), \
					(int)e->posy) && !check_map((int)e->posx, \
					(int)(e->posy - e->diry * e->movespeed)))
		{
			e->posx -= e->dirx * e->movespeed;
			e->posy -= e->diry * e->movespeed;
		}
		else
			ft_putchar('\a');
	}
	expose(e);
}

void		music(t_env *env)
{

	if (env->music)
	{
		system("killall afplay");
		env->music = 0;
	}
	else
	{
		system("afplay misc/theme.mp3&");
		env->music = 1;
	}
}

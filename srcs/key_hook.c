/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 12:05:57 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/26 13:13:52 by kwiessle         ###   ########.fr       */
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
		if (!searchinlist((int)(e->posx + e->dirx * e->movespeed), \
					(int)e->posy, e) && !searchinlist((int)e->posx, \
					(int)(e->posy + e->diry * e->movespeed), e))
		{
			e->posx += e->dirx * e->movespeed;
			e->posy += e->diry * e->movespeed;
		}
		else
			ft_putchar('\a');
	}
	if (keycode == DOWN)
	{
		if (!searchinlist((int)(e->posx - e->dirx * e->movespeed), \
					(int)e->posy, e) && !searchinlist((int)e->posx, \
					(int)(e->posy - e->diry * e->movespeed), e))
		{
			e->posx -= e->dirx * e->movespeed;
			e->posy -= e->diry * e->movespeed;
		}
		else
			ft_putchar('\a');
	}
	expose(e);
}

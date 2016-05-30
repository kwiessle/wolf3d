/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:28:49 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/30 14:38:58 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		get_texture(int x, int y, int color, t_env *e)
{
	while (y < e->drawend)
	{
		e->texy = (y * 2 - Y_WIN + e->lineheight) * 32 / e->lineheight;
		if (check_map(e->mapx, e->mapy) == 1)
			color = e->texture->tab1[64 * e->texy + e->texx];
		else if (check_map(e->mapx, e->mapy) == 2)
			color = e->texture->tab2[64 * e->texy + e->texx];
		else if (check_map(e->mapx, e->mapy) == 3)
			color = e->texture->tab3[64 * e->texy + e->texx];
		else if (check_map(e->mapx, e->mapy) == 4)
			color = e->texture->tab4[64 * e->texy + e->texx];
		e->buffer[y][x] = color;
		y++;
	}
	get_texture2(e);
	get_texture3(e, x, y);
}

void		get_texture2(t_env *e)
{
	if (!e->side && e->raydirx > 0)
	{
		e->floorwallx = e->mapx;
		e->floorwally = e->mapy + e->wallx;
	}
	else if (!e->side && e->raydirx < 0)
	{
		e->floorwallx = e->mapx + 1.0;
		e->floorwally = e->mapy + e->wallx;
	}
	else if (e->side == 1 && e->raydiry > 0)
	{
		e->floorwallx = e->mapx + e->wallx;
		e->floorwally = e->mapy;
	}
	else
	{
		e->floorwallx = e->mapx + e->wallx;
		e->floorwally = e->mapy + 1.0;
	}
	e->distwall = e->perpwalldist;
	e->distplayer = 0.0;
	if (e->drawend < 0)
		e->drawend = Y_WIN;
}

void		get_texture3(t_env *e, int x, int y)
{
	y = e->drawend;
	while (y < Y_WIN)
	{
		e->c_dist = Y_WIN / (2.0 * y - Y_WIN);
		e->weight = (e->c_dist - e->distplayer) / (e->distwall - e->distplayer);
		e->c_floorx = e->weight * e->floorwallx + (1.0 - e->weight) * e->posx;
		e->c_floory = e->weight * e->floorwally + (1.0 - e->weight) * e->posy;
		e->floortexx = (int)(e->c_floorx * 64) % 64;
		e->floortexy = (int)(e->c_floory * 64) % 64;
		e->buffer[y][x] = e->texture->floor[64 * e->floortexy + e->floortexx];
		e->buffer[Y_WIN - y][x] = e->texture->roof[64 * e->floortexy + \
								e->floortexx];
		y++;
	}
}

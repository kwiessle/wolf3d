/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 11:34:29 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/29 20:10:44 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_img		*init_img(t_env *env)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	img->img = mlx_new_image(env->mlx, X_WIN, Y_WIN);
	img->data = mlx_get_data_addr(img->img, &img->bpp, \
			&img->size_line, &img->endian);
	return (img);
}

void		pixel_to_img(t_env *env, int x, int y, int color)
{
	int		octet;

	octet = env->img->bpp / 8;
	if (x > 0 && x < X_WIN && y > 0 && y < Y_WIN)
		ft_memcpy(&env->img->data[octet * (x + env->img->size_line / \
					octet * y)], &color, octet);
}

void		draw_vertical(int x, t_env *env)
{
	if (env->drawstart < env->drawend)
	{
		while (env->drawstart <= env->drawend)
		{
			pixel_to_img(env, x, env->drawstart, env->color);
			env->drawstart++;
		}
	}
	else
	{
		while (env->drawstart >= env->drawend)
		{
			pixel_to_img(env, x, env->drawstart, env->color);
			env->drawstart--;
		}
	}
}

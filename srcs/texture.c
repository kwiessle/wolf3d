/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 11:58:23 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/30 14:15:43 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			**init_tab(t_env *env)
{
	int			**buffer;
	int			i;

	i = 0;
	if (!(buffer = (int **)malloc(sizeof(int *) * (Y_WIN + 1))))
		return (NULL);
	while (i < Y_WIN)
	{
		buffer[i] = &env->tab[i * X_WIN];
		i++;
	}
	buffer[i] = NULL;
	return (buffer);
}

t_texture	*create_texture(t_env *e)
{
	int			w;
	int			h;
	t_texture	*t;

	if (!(t = (t_texture *)malloc(sizeof(t_texture))))
		return (NULL);
	t->t_1 = mlx_xpm_file_to_image(e->mlx, "./misc/mur.xpm", &w, &h);
	t->tab1 = (int *)mlx_get_data_addr(t->t_1, &t->bpp, &t->size, &t->end);
	t->t_2 = mlx_xpm_file_to_image(e->mlx, "./misc/zdp.xpm", &w, &h);
	t->tab2 = (int *)mlx_get_data_addr(t->t_2, &t->bpp, &t->size, &t->end);
	t->t_3 = mlx_xpm_file_to_image(e->mlx, "./misc/crack.xpm", &w, &h);
	t->tab3 = (int *)mlx_get_data_addr(t->t_3, &t->bpp, &t->size, &t->end);
	t->t_4 = mlx_xpm_file_to_image(e->mlx, "./misc/aces.xpm", &w, &h);
	t->tab4 = (int *)mlx_get_data_addr(t->t_4, &t->bpp, &t->size, &t->end);
	t->t_floor = mlx_xpm_file_to_image(e->mlx, "./misc/floor.xpm", &w, &h);
	t->floor = (int *)mlx_get_data_addr(t->t_floor, &t->bpp, &t->size, &t->end);
	t->t_roof = mlx_xpm_file_to_image(e->mlx, "./misc/neon.xpm", &w, &h);
	t->roof = (int *)mlx_get_data_addr(t->t_roof, &t->bpp, &t->size, &t->end);
	return (t);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:30:01 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/30 15:05:05 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(void)
{
	t_env	*env;
	t_img	*menu;
	int		w;
	int		h;

	w = X_WIN;
	h = 200;
	if (!(menu = (t_img *)malloc(sizeof(t_img))))
		return (0);
	env = init_env();
	menu->img = mlx_xpm_file_to_image(env->mlx, "misc/menu.xpm", &w, &h);
	mlx_put_image_to_window(env->mlx, env->win, menu->img, 0, Y_WIN);
	expose(env);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:30:01 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/20 15:09:06 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
//#include "../textures/plasma_maze.xpm"

int		main(void)
{
	void	*mlx;
	void	*win;
	t_img	*img;
	int		i;

	i = 10;
	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (0);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 300, 300, "wolf3d");
	img->img = mlx_xpm_to_image(mlx, zdp, &i, &i);
	mlx_put_image_to_window(mlx, win, img->img, 0, 0);
	mlx_put_image_to_window(mlx, win, img->img, 128, 0);

	mlx_loop(mlx);
	return (0);
}

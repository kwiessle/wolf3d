/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 10:50:48 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/30 14:39:42 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		close_wolf(t_env *env)
{
	if (env->music)
		system("killall afplay");
	free(env);
	exit(EXIT_SUCCESS);
}

int		keyboard(int keycode, t_env *env)
{
	if (env->mlx == NULL)
		return (0);
	if (keycode == EXIT)
		close_wolf(env);
	if (keycode == LEFT)
		rot_left(env);
	if (keycode == RIGHT)
		rot_right(env);
	if (keycode == UP || keycode == DOWN)
		moove(keycode, env);
	if (keycode == MUSIC)
		music(env);
	if (keycode == L_MOVE)
		moove_left(env);
	if (keycode == R_MOVE)
		moove_right(env);
	return (0);
}

void	clear_tab(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < Y_WIN)
	{
		x = 0;
		while (x < X_WIN)
		{
			env->buffer[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	expose(t_env *e)
{
	clear_tab(e);
	mlx_hook(e->win, 2, 1, keyboard, e);
	mlx_hook(e->win, 17, 1L << 17, close_wolf, e);
	mlx_loop_hook(e->mlx, raycasting, e);
	mlx_loop(e->mlx);
}

void	music(t_env *env)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:28:40 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/30 14:51:57 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mlx.h"
# include "struct.h"
# include "define.h"
# include "time.h"
# include "math.h"

int			check_line(char *line);
int			check_border(char *line);
t_env		*init_env(void);
t_img		*init_img(t_env *env);
void		pixel_to_img(t_env *env, int x, int y, int color);
void		draw_vertical(int x, t_env *env);
int			raycasting(t_env *env);
void		get_color(t_env *env);
void		check_wall(t_env *env);
void		init_ray(t_env *env, int x);
int			keyboard(int keycode, t_env *env);
void		rot_left(t_env *env);
void		rot_right(t_env *env);
void		expose(t_env *env);
void		moove(int keycode, t_env *env);
int			**init_tab(t_env *env);
t_texture	*create_texture(t_env *env);
void		get_texture(int x, int y, int color, t_env *env);
void		get_texture2(t_env *env);
void		get_texture3(t_env *env, int x, int y);
void		clear_tab(t_env *env);
int			check_map(int x, int y);
void		music(t_env *env);
void		moove_left(t_env *env);
void		moove_right(t_env *env);
int			close_wolf(t_env *env);

#endif

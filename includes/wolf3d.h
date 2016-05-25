/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:28:40 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/25 15:01:34 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H


# include <stdio.h>


# include "libft.h"
# include "mlx.h"
# include "struct.h"
# include "define.h"
# include "time.h"
# include "math.h"
# include "../textures/plasma_maze.xpm"
# include "../textures/zdp.xpm"

t_map		*init_map(void);
t_map		*add_node(t_map *list, t_map *elem);
t_map		*convert_map(t_env *env, t_map *list, char *line);
t_map		*get_map(int fd, t_env *env);
int			check_line(char *line);
int			check_border(char *line);
t_env		*init_env(int fd);
t_img		*init_img(t_env *env);
void		pixel_to_img(t_env *env, int x, int y, int color);
void		draw_vertical(int x, t_env *env);
void		raycasting(t_env *env);
void		color(t_env *env);
void		check_wall(t_env *env);
void		init_ray(t_env *env, int x);
int			searchinlist(int x, int y, t_env *env);


#endif

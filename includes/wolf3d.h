/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:28:40 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/24 14:32:57 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H


# include <stdio.h>


# include "libft.h"
# include "mlx.h"
# include "struct.h"
# include "../textures/plasma_maze.xpm"
# include "../textures/zdp.xpm"

t_map		*init_map(void);
t_map		*add_node(t_map *list, t_map *elem);
t_map		*convert_map(t_map *list, char *line);
t_map		*get_map(int fd);

int			check_line(char *line);
int			check_border(char *line);

#endif

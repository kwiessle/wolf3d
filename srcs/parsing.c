/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 12:26:29 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/25 12:25:41 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map		*init_map(void)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->x = 0;
	map->y = 0;
	map->obj = 0;
	map->next = NULL;
	return (map);
}

t_map		*add_node(t_map *list, t_map *elem)
{
	t_map	*tmp;

	if (!list)
		return (elem);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (list);
}

t_map		*convert_map(t_env *env, t_map *list, char *line)
{
	int				x;
	char			**map;
	static	int		y;
	t_map			*elem;

	x = 0;
	map = ft_strsplit(line, ' ');
	while (map[x])
	{
		elem = init_map();
		elem->x = x;
		elem->y = y;
		elem->obj = ft_atoi(map[x]);
		list = add_node(list, elem);
		x++;
	}
	y++;
	env->xmax = x;
	env->ymax = y;
	free(map);
	return (list);
}

t_map		*get_map(int fd, t_env *env)
{
	char			*line;
	t_map			*new;
	static int		size;

	new = NULL;
	if (get_next_line(fd, &line))
	{
		size = ft_tablen(ft_strsplit(line, ' '));
		new = convert_map(env, new, line);
		check_line(line);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_tablen(ft_strsplit(line, ' ')) != size)
			ft_error("map isn't a square\n");
		check_border(line);
		new = convert_map(env, new, line);
	}
	check_line(line);
	return (new);
}

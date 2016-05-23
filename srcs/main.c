/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 15:17:36 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/23 17:43:57 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "stdio.h"

t_coord		*get_coord(char **map)
{
	t_coord		*coord;
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = 0;
	if (!(coord = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	while (map[y][i])
	{
		if (map[y][i] != ' ')
			x++;
		i++;
	}
	while (map[y])
		y++;
	coord->x = x;
	coord->y = y;
//	printf("%d %d\n\n", coord->x, coord->y);
	return (coord);
}

char		**epur_tabchar(char **map)
{
	t_coord		*coord;
	char		**new;
	int			x;
	int			y;
	int		i;

	coord = get_coord(map);
//	printf("%d\n", coord->y);
	y = 0;
	i = 0;
	new = (char **)malloc(sizeof(char) * (coord->y + 1));
	while (map[y])
	{
		x = 0;
		i = 0;
		new[y] = ft_strnew(coord->x + 1);
		while (map[y][i])
		{
			if (map[y][i] != ' ')
			{
				new[y][x] = map[y][i];
				printf("[%c]\n", new[y][x]);
				x++;
			}
			i++;
		}
		new[y][i] = '\0';
		y++;
	}
	new[y] = 0;
	return (new);
}

int			main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	*big;
	char	**map;
	char	**tmp;
	int		i;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	big = ft_strnew(0);
	while (get_next_line(fd, &line) > 0)
	{
		big = ft_strjoin(big, line);
		big = ft_strjoin(big, "\n");
	}
	map = ft_strsplit(big, '\n');
	tmp = epur_tabchar(map);
	free(map);
	map = tmp;
	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

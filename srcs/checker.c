/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:26:53 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/24 15:44:25 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			ft_error("Border Map Error");
		i++;
	}
	return (0);
}

int		check_border(char *line)
{
	static int i = 0;

	if (i == 0)
	{
		while (line[i])
			i++;
	}
	if (line[0] != '1' || line[i - 1] != '1')
		ft_error("Border Map Error");
	return (0);
}

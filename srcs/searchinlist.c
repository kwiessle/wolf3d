/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchinlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 14:18:31 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/25 14:20:54 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		searchinlist(int x, int y, t_env *env)
{
	t_map	*tmp;

	tmp = env->map;
	while (tmp)
	{
		if (tmp->x == x && tmp->y == y)
			return (tmp->obj);
		tmp = tmp->next;
	}
	return (1);
}

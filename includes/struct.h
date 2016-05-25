/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:08:50 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/25 12:44:07 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_map
{
	int				x;
	int				y;
	int				obj;
	struct s_map	*next;
}					t_map;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_env
{
	int				xmax;
	int				ymax;
	void			*mlx;
	void			*win;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	clock_t			time;
	clock_t			oldtime;
	double			fps;
	double			camx;
	int				mapx;
	int				mapy;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			sidedirx;
	double			sidediry;
	double			deltx;
	double			delty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
	double			movespeed;
	double			rotspeed;
	t_map			*map;
	t_img			*img;
}					t_env;


#endif

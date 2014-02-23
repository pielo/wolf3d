/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 18:53:00 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/15 16:00:01 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <libft.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <libft/includes/libft.h>
# include <libft/includes/get_next_line.h>

# define HEIGHT 600
# define WIDTH 800

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_vert
{
	int			start;
	int			end;
}				t_vert;

typedef struct	s_im
{
	char        *imag;
	int         size_line;
	int         bpp;
	int         endian;
}               t_im;

typedef struct	s_info
{
	t_pos		player;
	t_pos		direction;
	t_pos		plane;
	t_pos		raypos;
	t_pos		raydir;
	t_pos		map;
	t_pos		sidedist;
	t_pos		deltadist;
	t_pos		step;
	int			color;
	t_im		image;
}				t_info;

typedef struct	s_env
{
	void        *mlx;
	void        *win;
	void		*img_ptr;
	t_info      data;
}               t_env;

double	ft_fabs(double nbr);
int		ft_abs(int nbr);
int		ft_color(int val);
int		ft_calc(t_info donnees, t_env e);
void	ft_hit(int *side, t_info *donnees, int worldmap[24][24]);
t_vert	ft_init_draw(int side, t_info donnees);
void	ft_draw(t_im im, int x, int y, int color);

#endif

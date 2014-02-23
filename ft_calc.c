/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 16:03:23 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/15 15:54:52 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <math.h>
#include <wolf3d.h>
#include <map.h>

static int		ft_neg(double ray, double *sided, double mapi, double deltad)
{
	*sided = (ray - mapi) * deltad;
	return (-1);
}

static int		ft_pos(double ray, double *sided, double mapi, double deltad)
{
	*sided = (mapi + 1.0 - ray) * deltad;
	return (1);
}

static t_info	ft_init_data(t_info d, double camerax)
{
	d.raypos.x = d.player.x;
	d.raypos.y = d.player.y;
	d.raydir.x = d.direction.x + d.plane.x * camerax;
	d.raydir.y = d.direction.y + d.plane.y * camerax;
	d.map.x = d.raypos.x;
	d.map.y = d.raypos.y;
	d.deltadist.x = sqrt(1 + (d.raydir.y * d.raydir.y)
			/ (d.raydir.x * d.raydir.x));
	if (d.deltadist.x == -1)
		ft_putstr(strerror(errno));
	d.deltadist.y = sqrt(1 + (d.raydir.x * d.raydir.x)
			/ (d.raydir.y * d.raydir.y));
	if (d.deltadist.x == -1)
		ft_putstr(strerror(errno));
	if (d.raydir.x < 0)
		d.step.x = ft_neg(d.raypos.x, &(d.sidedist.x), d.map.x, d.deltadist.x);
	else
		d.step.x = ft_pos(d.raypos.x, &(d.sidedist.x), d.map.x, d.deltadist.x);
	if (d.raydir.y < 0)
		d.step.y = ft_neg(d.raypos.y, &(d.sidedist.y), d.map.y, d.deltadist.y);
	else
		d.step.y = ft_pos(d.raypos.y, &(d.sidedist.y), d.map.y, d.deltadist.y);
	return (d);
}

int				ft_calc(t_info data, t_env e)
{
	t_pos		coord;
	int			side;
	t_vert		draw;
	double		camerax;

	coord.x = 0;
	while (coord.x < WIDTH)
	{
		coord.y = 0;
		camerax = 2 * coord.x / WIDTH - 1;
		data = ft_init_data(data, camerax);
		ft_hit(&side, &data, worldmap);
		draw = ft_init_draw(side, data);
		while (coord.y < HEIGHT)
		{
			data.color = ft_color(worldmap[(int)data.map.x][(int)data.map.y]);
			if (!(coord.y >= draw.start && coord.y <= draw.end))
				data.color = 0x000000;
			ft_draw(data.image, coord.x, coord.y, data.color);
			coord.y += 1;
		}
			coord.x += 1;
	}
	mlx_put_image_to_window(e.mlx, e.win, e.img_ptr, 0, 0);
	return (0);
}

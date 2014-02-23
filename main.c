/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 17:34:01 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/23 13:34:51 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <wolf3d.h>
#include <time.h>

static int		key_hook(int keycode, t_info *donnees)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362)
	{
		donnees->player.x += donnees->direction.x;
		donnees->player.y += donnees->direction.y;
	}
	if (keycode == 65364)
	{
		donnees->player.x -= donnees->direction.x;
		donnees->player.y -= donnees->direction.y;
	}
	return (0);
}

static int		expose_hook(t_env *e)
{
	ft_calc(e->data, *e);
	return (0);
}

int				main(int argc, char **argv)
{
	t_env		e;

	e.data.player.x = 22;
	e.data.player.y = 12;
	e.data.direction.x = -1;
	e.data.direction.y = 0;
	e.data.plane.x = 0;
	e.data.plane.y = 0.66;
	(void)argc;
	(void)argv;
	e.mlx = mlx_init();
	if (!e.mlx)
		return (1);
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "wolf3d");
	mlx_key_hook(e.win, key_hook, &e.data);
	e.img_ptr = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.data.image.imag = mlx_get_data_addr(e.img_ptr,
			&e.data.image.bpp, &e.data.image.size_line, &e.data.image.endian);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}

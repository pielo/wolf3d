/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 18:31:21 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/07 18:42:38 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_vert		ft_init_draw(int side, t_info donnees)
{
	t_vert	draw2;
	double	perpwalldist;
	int		lineheight;

	if (side == 0)
		perpwalldist = ft_fabs((donnees.map.x - donnees.raypos.x
					+ (1 - donnees.step.x) / 2) / donnees.raydir.x);
	else
		perpwalldist = ft_fabs((donnees.map.y - donnees.raypos.y
					+ (1 - donnees.step.y) / 2) / donnees.raydir.y);
	lineheight = ft_abs(HEIGHT / perpwalldist);
	if ((draw2.start = ((-lineheight / 2) + (HEIGHT / 2))) < 0)
		draw2.start = 0;
	if ((draw2.end = ((lineheight / 2) + (HEIGHT / 2))) >= HEIGHT)
		draw2.end = HEIGHT - 1;
	return (draw2);
}

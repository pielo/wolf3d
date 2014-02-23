/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 18:03:43 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/07 18:24:48 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		ft_hit(int *side, t_info *donnees, int worldmap[24][24])
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if ((donnees->sidedist.x) < (donnees->sidedist.y))
		{
			(donnees->sidedist.x) += (donnees->deltadist.x);
			(donnees->map.x) += (donnees->step.x);
			*side = 0;
		}
		else
		{
			(donnees->sidedist.y) += (donnees->deltadist.y);
			(donnees->map.y) += (donnees->step.y);
			*side = 1;
		}
		if (worldmap[(int)(donnees->map.x)][(int)(donnees->map.y)] > 0)
			hit = 1;
	}
}

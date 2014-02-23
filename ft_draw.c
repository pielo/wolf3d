/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 16:51:22 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/15 15:55:33 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	ft_draw(t_im im, int x, int y, int color)
{
	int	i;
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	i = 0;
	while (i < im.bpp / 8)
	{
		index = (y * im.size_line) + (x * (im.bpp / 8)) + i;
		im.imag[index] = color >> (i * 8) & 0xFF;
		i++;
	}
}

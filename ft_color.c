/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 19:00:49 by mlanglet          #+#    #+#             */
/*   Updated: 2014/01/06 19:30:52 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_color(int val)
{
	int		color;

	color = 0xFFFFFF;
	if (val == 1)
		color = 0xFF0000;
	if (val == 2)
		color = 0x00FF00;
	if (val == 3)
		color = 0x0000FF;
	if (val == 4)
		color = 0xFFFF00;
	return (color);
}

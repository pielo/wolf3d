/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:35:56 by mlanglet          #+#    #+#             */
/*   Updated: 2013/12/05 11:27:16 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/libft.h"

void	ft_strdel(char **as)
{
		ft_memdel((void**) as);
}

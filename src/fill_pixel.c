/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:03:00 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/18 14:36:28 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_pixel(int *img_data, int x, int y, t_env *e)
{
	if ((y > 0 && x > 0) && (y < e->win_y && x < e->win_x) &&
	img_data[y * e->win_x + x] == 0)
		img_data[y * e->win_x + x] = e->color;
}

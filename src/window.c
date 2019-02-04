/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:05:20 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/11 10:09:32 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	window(t_env *e)
{
	e->win_y = 1400;
	e->win_x = 2560;
	while (e->win_y > (e->lenght * e->zoom))
		e->win_y--;
	if ((e->win_y + 600) <= 1400)
		e->win_y += 600;
	while (e->win_x > (e->width * e->zoom))
		e->win_x--;
	if ((e->win_x + 600) <= 2560)
		e->win_x += 600;
	if (e->win_x == 2560)
	{
		while (((e->width * e->zoom + 50)) > e->win_x)
			e->zoom--;
	}
	if (e->win_y == 1400)
	{
		while (((e->lenght * e->zoom + 50)) > e->win_y)
			e->zoom--;
	}
}

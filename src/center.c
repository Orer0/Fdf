/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:38:52 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/13 23:37:26 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		center(t_env *e)
{
	int mid_x;
	int mid_y;

	if (e->cap2 == 0)
	{
		mid_x = (e->width * e->zoom) / 2;
		mid_y = (e->lenght * e->zoom) / 2;
		if (e->proj == 42)
		{
			e->dec_y = (e->win_y / 2) - (mid_y);
			e->dec_x = ((e->win_x / 2) - (mid_x)) + (BACK / 2);
		}
		if (e->proj == 0)
		{
			e->dec_y = (e->win_y / 2) - ((mid_y) * 2.5);
			e->dec_x = (e->win_x / 2) - (mid_x - 150) + (BACK / 2);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 20:16:41 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/18 14:36:46 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fill_map(t_env *e)
{
	t_bres b;

	e->proj == ISO ? iso(e) : para(e);
	while (e->j < e->lenght)
	{
		while (e->n < e->width)
		{
			if (e->n < e->width - 1)
			{
				e->cap = 1;
				bresenham(e, &b);
			}
			if (e->j < e->lenght - 1)
			{
				e->cap = 2;
				bresenham(e, &b);
			}
			e->cap = 0;
			e->n++;
		}
		e->j++;
		e->n = 0;
	}
	return (0);
}

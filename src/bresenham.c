/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:00:17 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/17 20:35:12 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bresenham(t_env *e, t_bres *b)
{
	center(e);
	if (e->cap == 1)
	{
		b->dx = ft_abs(e->tab[e->j][e->n + 1].x - e->tab[e->j][e->n].x);
		b->dy = -ft_abs(e->tab[e->j][e->n + 1].y - e->tab[e->j][e->n].y);
		b->scale_x = e->tab[e->j][e->n].x < e->tab[e->j][e->n + 1].x ? 1 : -1;
		b->scale_y = e->tab[e->j][e->n].y < e->tab[e->j][e->n + 1].y ? 1 : -1;
		b->x1 = e->tab[e->j][e->n + 1].x + e->dec_x;
		b->y1 = e->tab[e->j][e->n + 1].y + e->dec_y;
	}
	if (e->cap == 2)
	{
		b->dx = ft_abs(e->tab[e->j + 1][e->n].x - e->tab[e->j][e->n].x);
		b->dy = -ft_abs(e->tab[e->j + 1][e->n].y - e->tab[e->j][e->n].y);
		b->scale_x = e->tab[e->j][e->n].x < e->tab[e->j + 1][e->n].x ? 1 : -1;
		b->scale_y = e->tab[e->j][e->n].y < e->tab[e->j + 1][e->n].y ? 1 : -1;
		b->x1 = e->tab[e->j + 1][e->n].x + e->dec_x;
		b->y1 = e->tab[e->j + 1][e->n].y + e->dec_y;
	}
	b->x = e->tab[e->j][e->n].x + e->dec_x;
	b->y = e->tab[e->j][e->n].y + e->dec_y;
	b->err = 0;
	b->fault = b->dx + b->dy;
	fill_line(b, e);
}

void	fill_line(t_bres *b, t_env *e)
{
	b->boolen = 1;
	while (b->x != b->x1 || b->y != b->y1)
	{
		fill_pixel(e->img_data, b->x, b->y, e);
		b->err = 2 * b->fault;
		if (b->err >= b->dy)
		{
			b->fault += b->dy;
			b->x += b->scale_x;
		}
		if (b->err <= b->dx)
		{
			b->fault += b->dx;
			b->y += b->scale_y;
		}
		b->boolen = 0;
	}
	fill_pixel(e->img_data, b->x, b->y, e);
}

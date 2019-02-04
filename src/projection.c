/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:23:35 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/14 22:04:06 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		para_z(t_env *e, int j, int n)
{
	if (e->tab[j][n].z > 0)
	{
		e->tab[j][n].x = (e->x + (CTE * (e->tab[j][n].z * e->alt)));
		e->tab[j][n].y = e->y +
			(((CTE / 2) + (CTE % 2)) * (e->tab[j][n].z * e->alt));
	}
	else
	{
		e->tab[j][n].x = (e->x + (CTE * (e->tab[j][n].z * -1)));
		e->tab[j][n].y = e->y +
			(((CTE / 2) + (CTE % 2)) * (e->tab[j][n].z * -1));
	}
	return (0);
}

int		iso_z(t_env *e, int j, int n)
{
	if (e->tab[j][n].z > 0)
	{
		e->tab[j][n].x = ((CTE * e->x) - (CTE2 * e->y));
		e->tab[j][n].y = (e->tab[j][n].z * e->alt) +
	((((CTE / 2) + (CTE % 2)) * e->x) + (((CTE2 / 2) + (CTE2 % 2)) * e->y));
	}
	else
	{
		e->tab[j][n].x = ((CTE * e->x) - (CTE2 * e->y));
		e->tab[j][n].y = (e->tab[j][n].z * -1) +
	((((CTE / 2) + (CTE % 2)) * e->x) + (((CTE2 / 2) + (CTE2 % 2)) * e->y));
	}
	return (0);
}

int		para(t_env *e)
{
	int j;
	int n;

	j = 0;
	n = 0;
	while (j < e->lenght)
	{
		while (n < e->width)
		{
			e->x = e->tab[j][n].x;
			e->y = e->tab[j][n].y;
			para_z(e, j, n);
			n++;
		}
		n = 0;
		j++;
	}
	return (0);
}

int		iso(t_env *e)
{
	int j;
	int n;

	j = 0;
	n = 0;
	while (j < e->lenght)
	{
		while (n < e->width)
		{
			e->x = e->tab[j][n].x;
			e->y = e->tab[j][n].y;
			iso_z(e, j, n);
			n++;
		}
		n = 0;
		j++;
	}
	return (0);
}

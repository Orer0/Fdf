/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 20:07:32 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/18 12:14:32 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	clear_img(int *img_data, t_env *e)
{
	int x;

	x = 0;
	while (x < e->win_x * e->win_y)
	{
		img_data[x] = BLACK;
		x++;
	}
}

void	exit_fdf(t_env *e)
{
	mlx_destroy_window(e->mlx_ptr, e->win_ptr);
	ft_memdel((void **)e->tab);
	exit(0);
}

void	free_tab(t_env *e)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < e->lenght)
	{
		ft_memdel((void **)e->tab);
		ft_memdel((void **)&e->tab[i]);
		i++;
	}
}

void	init(t_env *e)
{
	mlx_clear_window(e->mlx_ptr, e->win_ptr);
	free_tab(e);
	e->lenght = 0;
	e->width = 0;
	e->j = 0;
	e->n = 0;
	e->cap = 0;
	e->xdecal = 0;
	e->ydecal = 0;
	e->cap2 = 42;
	e->key = 1;
}

int		key_run(int keycode, t_env *e)
{
	init(e);
	if (keycode == ESC_KEY)
		exit_fdf(e);
	else if (keycode == C)
	{
		e->col += 1;
		color(e);
	}
	else if (keycode == E || keycode == Q)
		altitude(e, keycode);
	else if (keycode == S || keycode == D || keycode == A || keycode == W)
		move(e, keycode);
	else if (keycode == P || keycode == I)
		change_proj(e, keycode);
	else if (keycode == MORE)
		zoom(e);
	else if (keycode == LESS)
		dezoom(e);
	background(e);
	mlx_put_image_to_window(e->mlx_ptr, e->win_ptr, e->img_ptr, POS_X, POS_Y);
	menu(e);
	return (0);
}

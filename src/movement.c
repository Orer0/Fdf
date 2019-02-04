/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:46:40 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/17 20:30:29 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change_proj(t_env *e, int keycode)
{
	clear_img(e->img_data, e);
	e->cap2 = 0;
	if (keycode == P)
		e->proj = 42;
	if (keycode == I)
		e->proj = 0;
	make_tab(e);
	set_tab(e);
	fill_map(e);
}

void	move(t_env *e, int keycode)
{
	clear_img(e->img_data, e);
	if (keycode == S)
		e->dec_y += 10;
	if (keycode == D)
		e->dec_x += 10;
	if (keycode == A)
		e->dec_x -= 10;
	if (keycode == W)
		e->dec_y -= 10;
	make_tab(e);
	set_tab(e);
	fill_map(e);
}

void	altitude(t_env *e, int keycode)
{
	clear_img(e->img_data, e);
	if (keycode == E && e->alt < 10)
		e->alt += 1;
	if (keycode == Q && e->alt > -10)
		e->alt -= 1;
	make_tab(e);
	set_tab(e);
	fill_map(e);
}

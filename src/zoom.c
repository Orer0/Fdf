/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 18:41:59 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/17 20:45:58 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		dezoom(t_env *e)
{
	clear_img(e->img_data, e);
	if (e->zoom > 9)
	{
		if (e->proj == PARA && e->zoom > 3)
		{
			e->zoom -= 3;
			e->dec_y += 15;
			e->dec_x += 25;
		}
		if (e->proj == ISO && e->zoom > 3)
		{
			e->zoom -= 3;
			e->dec_y += 40;
			e->dec_x += 10;
		}
	}
	make_tab(e);
	set_tab(e);
	fill_map(e);
}

void		zoom(t_env *e)
{
	clear_img(e->img_data, e);
	if (e->proj == PARA)
	{
		e->zoom += 3;
		e->dec_y -= 15;
		e->dec_x -= 25;
	}
	if (e->proj == ISO)
	{
		e->zoom += 3;
		e->dec_y -= 40;
		e->dec_x -= 10;
	}
	make_tab(e);
	set_tab(e);
	fill_map(e);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 20:35:23 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/18 12:20:21 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	color(t_env *e)
{
	clear_img(e->img_data, e);
	if (e->col == 1)
		e->color = RED;
	else if (e->col == 2)
		e->color = YELLOW;
	else if (e->col == 3)
		e->color = BLUE;
	else if (e->col == 4)
		e->color = GREEN;
	else if (e->col == 5)
		e->color = PINK;
	else if (e->col == 6)
		e->color = ORANGE;
	else if (e->col == 7)
	{
		e->color = WHITE;
		e->col = 1;
	}
	make_tab(e);
	set_tab(e);
	fill_map(e);
}

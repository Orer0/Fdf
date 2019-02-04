/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:58:59 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/15 20:11:53 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_point(t_env *e, int y)
{
	int x;

	x = 0;
	while (x < e->width)
	{
		e->tab[y][x].z = ft_atoi(e->split[x]);
		e->tab[y][x].x = e->xdecal;
		e->tab[y][x].y = e->ydecal;
		ft_strdel(&e->split[x]);
		x++;
		e->xdecal += e->zoom;
	}
	if (x <= 1)
		erreur(1);
}

int		set_tab(t_env *e)
{
	int y;

	y = 0;
	if ((e->fd = open(e->av, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(e->fd, &e->line) > 0)
	{
		e->split = ft_strsplit(e->line, ' ');
		set_point(e, y);
		free(e->split);
		e->xdecal = 0;
		e->ydecal += e->zoom;
		y++;
		ft_strdel(&e->line);
	}
	ft_strdel(&e->line);
	if (y < 1)
		erreur(1);
	return (0);
}

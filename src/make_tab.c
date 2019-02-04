/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:07:19 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/18 14:31:37 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		make_tab(t_env *e)
{
	int		check;

	check = 0;
	if ((e->fd = open(e->av, O_RDONLY)) < 0)
		erreur(1);
	while (get_next_line(e->fd, &e->line) > 0)
	{
		e->width = ft_count_words(e->line, ' ');
		if (e->lenght == 0)
			check = e->width;
		if (check != e->width)
			erreur(2);
		e->lenght++;
		ft_strdel(&e->line);
	}
	ft_strdel(&e->line);
	close(e->fd);
	malloc_tab(e);
	return (0);
}

int		malloc_tab(t_env *e)
{
	int		i;

	i = 0;
	if (e->tab == NULL)
	{
		if (!(e->tab = (t_pixel **)ft_memalloc(e->lenght * sizeof(t_pixel *))))
			return (-1);
	}
	while (i < e->lenght)
	{
		if (!(e->tab[i] = (t_pixel *)ft_memalloc(e->width * sizeof(t_pixel))))
			return (-1);
		i++;
	}
	return (0);
}

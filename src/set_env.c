/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:19:45 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/18 12:11:32 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_env		*set_env(char *av, t_env *e)
{
	e->lenght = 0;
	e->width = 0;
	e->line = NULL;
	e->av = av;
	e->split = NULL;
	e->ydecal = 0;
	e->xdecal = 0;
	e->j = 0;
	e->n = 0;
	e->zoom = 30;
	e->cap = 0;
	e->cap2 = 0;
	e->proj = PARA;
	e->dec_y = 0;
	e->dec_x = 0;
	e->alt = -1;
	e->key = 0;
	e->tab = NULL;
	e->color = WHITE;
	e->col = 1;
	return (e);
}

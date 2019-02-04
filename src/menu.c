/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 23:28:21 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/18 12:20:15 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	menu(t_env *e)
{
	mlx_string_put(e->mlx_ptr, e->win_ptr, 35, 150, GREEN, "PROJECTION");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 35, 160, GREEN, "----------");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 5, 190, RED, "Isometrie : I");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 5, 210, RED, "Parallel : P");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 55, 300, GREEN, "MOVE");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 55, 310, GREEN, "----");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 5, 340, RED, "Up : W");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 5, 360, RED, "Down : S");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 5, 380, RED, "Left : A");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 5, 400, RED, "Right : D");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 55, 450, GREEN, "ZOOM");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 55, 460, GREEN, "----");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 5, 490, RED, "More : +");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 5, 510, RED, "Less : -");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 40, 600, GREEN, "ALTITUDE");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 40, 610, GREEN, "--------");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 5, 640, RED, "More : Q");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 5, 660, RED, "Less : P");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 55, 750, GREEN, "COLOR");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 55, 760, GREEN, "-----");
	mlx_string_put(e->mlx_ptr, e->win_ptr, 5, 790, RED, "Change : C");
}

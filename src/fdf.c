/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 19:00:09 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/18 14:35:04 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_env e;

	if (ac == 2)
	{
		set_env(av[1], &e);
		make_tab(&e);
		window(&e);
		set_tab(&e);
		e.mlx_ptr = mlx_init();
		e.win_ptr = mlx_new_window(e.mlx_ptr, e.win_x, e.win_y, "fdf");
		e.img_ptr = mlx_new_image(e.mlx_ptr, e.win_x, e.win_y);
		e.img_data = (int *)mlx_get_data_addr(e.img_ptr,
				&e.bpp, &e.s_l, &e.endian);
		fill_map(&e);
		background(&e);
		mlx_put_image_to_window(e.mlx_ptr, e.win_ptr, e.img_ptr, POS_X, POS_Y);
		menu(&e);
		mlx_hook(e.win_ptr, KEYPRESS, KEYPRESSMASK, key_run, &e);
		mlx_loop(e.mlx_ptr);
	}
	else
		erreur(1);
	return (0);
}

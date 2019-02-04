/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 15:23:38 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/14 16:53:59 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	erreur(int type)
{
	if (type == 1)
		ft_putstr("Argument incorrect\n");
	if (type == 2)
	{
		ft_putstr("Map incorrecte\n");
		ft_putstr("\nSeules les maps rectangles sont acceptees\n");
	}
	exit(1);
}

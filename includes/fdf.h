/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 15:08:40 by aroblin           #+#    #+#             */
/*   Updated: 2018/06/18 14:32:04 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "mlx.h"
# include "../libft/libft.h"

# define CTE 1
# define CTE2 1
# define POS_X 0
# define POS_Y 0
# define BACK 150
# define ISO 0
# define PARA 42

# define RED 0xFF0000
# define BLUE 0x003399
# define PINK 0xFF358B
# define ORANGE 0xFBAA00
# define GREEN 0x00FF00
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00

# define KEYPRESSMASK (1L<<0)
# define KEYPRESS 2

# define ESC_KEY 53
# define A 0
# define C 8
# define D 2
# define E 14
# define I 34
# define P 35
# define Q 12
# define S 1
# define W 13
# define MORE 24
# define LESS 27

typedef struct		s_pixel
{
	int				x;
	int				y;
	int				z;
}					t_pixel;

typedef struct		s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				*img_data;
	t_pixel			**tab;
	char			**split;
	char			*line;
	char			*av;
	int				win_x;
	int				win_y;
	int				bpp;
	int				s_l;
	int				endian;
	int				lenght;
	int				width;
	int				fd;
	int				ydecal;
	int				xdecal;
	int				x;
	int				y;
	int				z;
	int				j;
	int				n;
	int				zoom;
	int				cap;
	int				proj;
	int				cap2;
	int				alt;
	int				dec_y;
	int				dec_x;
	int				key;
	int				color;
	int				col;
}					t_env;

typedef struct		s_bres
{
	int				dx;
	int				dy;
	int				fault;
	int				err;
	int				scale_x;
	int				scale_y;
	int				boolen;
	int				x;
	int				y;
	int				x1;
	int				y1;
}					t_bres;

t_env				*set_env(char *av, t_env *e);

void				window(t_env *e);

int					make_tab(t_env *e);
int					malloc_tab(t_env *e);

int					set_tab(t_env *e);

void				bresenham(t_env *e, t_bres *b);
void				fill_line(t_bres *b, t_env *e);

int					fill_map(t_env *e);

int					iso(t_env *e);
int					para(t_env *e);

void				fill_pixel(int *img_data, int x, int y, t_env *e);

int					key_run(int keycode, t_env *e);
void				clear_img(int *img_data, t_env *e);
void				dezoom(t_env *e);
void				zoom(t_env *e);
void				color(t_env *e);
void				move(t_env *e, int keycode);
void				change_proj(t_env *e, int keycode);
void				altitude(t_env *e, int keycode);
void				free_tab(t_env *e);

int					center(t_env *e);

void				menu(t_env *e);
void				background(t_env *e);
void				erreur(int type);
#endif

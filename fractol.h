/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:32:43 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/25 12:40:43 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include "./libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define ESC			53
# define LEFT			123
# define RIGHT			124
# define UP				126
# define DOWN			125
# define KEY_C			8
# define KEY_I			34
# define KEY_R			15
# define KEY_H			4
# define WHEEL_UP		4
# define WHEEL_DOWN		5

# define HEIGHT			900
# define WIDTH			900
# define IMGAD(x, y, z, a)	mlx_get_data_addr(x, y, z, a)
# define ABS(x)			((x) < 0 ? -(x) : (x))

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_sierp
{
	void				*win;
	void				*img_ptr;
	char				*img;
	int					x;
	int					y;
	int					a;
	int					i;
	t_point				p;
}						t_sierp;

typedef struct			s_carpet
{
	void				*win;
	void				*img_ptr;
	char				*img;
	int					x;
	int					y;
	int					a;
	int					i;
	int					b;
	t_point				p;
}						t_carpet;

typedef struct			s_circle
{
	void				*win;
	void				*img_ptr;
	char				*img;
	int					x;
	int					y;
	int					i;
	int					a;
	t_point				p;
}						t_circle;

typedef struct			s_mandel
{
	void				*win;
	void				*img_ptr;
	char				*img;
	int					i_max;
	double				k;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				zoom_x;
	double				zoom_y;
	double				z_i;
	double				z_r;
	double				c_i;
	double				c_r;
}						t_mandel;

typedef struct			s_julia
{
	void				*win;
	void				*img_ptr;
	char				*img;
	int					i_max;
	int					move;
	double				k;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				zoom_x;
	double				zoom_y;
	double				z_i;
	double				z_r;
	double				c_i;
	double				c_r;
}						t_julia;

typedef struct			s_menger
{
	void				*win;
	void				*img_ptr;
	char				*img;
	int					x;
	int					y;
	int					a;
	int					i;
	int					b;
	t_point				p;
}						t_menger;

typedef struct			s_env
{
	void				*mlx;
	double				r;
	double				img_x;
	double				img_y;
	int					end;
	int					bpp;
	int					sl;
	int					menger;
	int					sierp;
	int					carpet;
	int					circle;
	int					mandel;
	int					julia;
	int					c;
	t_menger			*men;
	t_julia				*j;
	t_mandel			*m;
	t_sierp				*s;
	t_carpet			*carp;
	t_circle			*ci;
}						t_env;

void					ft_clean(t_env *e);
void					ft_error(int error);
int						check_av(int ac, char **av, t_env *e);
int						init_env(t_env *e);
int						create_image(t_env *e);
void					ft_draw_line(t_point p1, t_point p2, t_env *e);
int						check_for_x_y(int x, int y, t_env *e);
void					handle_win_help(t_env *e);
int						hsv_to_rgb(int i, t_env *e);
void					draw_color_sierp(t_env *e, int x, int y);
t_color					*get_sierp_color(t_env *e);
t_color					*get_color(int i, int imax, t_env *e);
t_color					*get_menger_color(int i);
void					draw_menger(int x, int y, int a, t_env *e);
void					menger_line(t_point p1, t_point p2, t_env *e, int i);
void					draw_color_menger(t_env *e, int x, int y, int i);

void					carpet(t_env *e, t_point p, int a, int i);
void					circle(t_env *e, t_point p, int r, int i);
void					sierp(t_env *e, t_point p, int a, int i);
void					menger(t_env *e, t_point p, int a, int i);
void					mandel(t_env *e);
void					julia(t_env *e);

int						init_sierp(t_sierp *s, t_env *e);
int						init_mandel(t_mandel *m, t_env *e);
int						init_julia(t_julia *j, t_env *e);
int						init_circle(t_circle *ci, t_env *e);
int						init_carpet(t_carpet *carp, t_env *e);
int						init_menger(t_menger *men, t_env *e);

int						expose_hook(t_env *e);

int						sierp_mouse_events(int button, int x, int y, t_env *e);
int						menger_key_events(int key, t_env *e);
int						sierp_key_events(int key, t_env *e);
int						circle_key_events(int key, t_env *e);
int						carp_key_events(int key, t_env *e);
int						mandel_key_events(int key, t_env *e);
int						mouse_events(int button, int x, int y, t_env *e);
int						move_c(int x, int y, t_env *e);
int						julia_mouse_events(int button, int x, int y, t_env *e);
int						julia_key_events(int key, t_env *e);
void					sierp_pos(int keycode, t_env *e);
void					circle_pos(int keycode, t_env *e);
void					carpet_pos(int keycode, t_env *e);
void					menger_pos(int keycode, t_env *e);
void					handle_fractal(t_env *e);
#endif

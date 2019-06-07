/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 12:36:50 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/15 18:31:07 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_pixel(t_env *e, int i, int x, int y)
{
	t_color	*color;
	int		p;

	color = get_color(i, e->m->i_max, e);
	p = x * 4 + y * e->sl;
	if (check_for_x_y(x, y, e))
	{
		e->m->img[p] = color->b;
		e->m->img[p + 1] = color->g;
		e->m->img[p + 2] = color->r;
	}
}

void			get_z_c(t_env *e, int x, int y)
{
	e->m->c_r = x / e->m->zoom_x + e->m->x1;
	e->m->c_i = y / e->m->zoom_y + e->m->y1;
	e->m->z_r = 0;
	e->m->z_i = 0;
}

void			mandel(t_env *e)
{
	int		x;
	int		y;
	int		i;
	double	tmp;

	x = -1;
	while (++x < e->img_x)
	{
		y = -1;
		while (++y < e->img_y)
		{
			get_z_c(e, x, y);
			i = 0;
			while (pow(e->m->z_r, 2) + pow(e->m->z_i, 2) < 4 && i < e->m->i_max)
			{
				tmp = e->m->z_r;
				e->m->z_r = pow(e->m->z_r, 2) - pow(e->m->z_i, 2) + e->m->c_r;
				e->m->z_i = 2 * e->m->z_i * tmp + e->m->c_i;
				i++;
			}
			if (i != e->m->i_max)
				draw_pixel(e, i, x, y);
		}
	}
}

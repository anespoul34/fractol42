/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 15:03:26 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/15 18:30:59 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_jul_pix(t_env *e, int i, int x, int y)
{
	t_color	*color;
	int		p;

	color = get_color(i, e->j->i_max, e);
	p = x * 4 + y * e->sl;
	if (check_for_x_y(x, y, e))
	{
		e->j->img[p] = color->b;
		e->j->img[p + 1] = color->g;
		e->j->img[p + 2] = color->r;
	}
}

void	julia(t_env *e)
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
			e->j->z_r = x / e->j->zoom_x + e->j->x1;
			e->j->z_i = y / e->j->zoom_y + e->j->y1;
			i = 0;
			while (pow(e->j->z_r, 2) + pow(e->j->z_i, 2) < 4 && i < e->j->i_max)
			{
				tmp = e->j->z_r;
				e->j->z_r = pow(e->j->z_r, 2) - pow(e->j->z_i, 2) + e->j->c_r;
				e->j->z_i = 2 * e->j->z_i * tmp + e->j->c_i;
				i++;
			}
			if (i != e->j->i_max)
				draw_jul_pix(e, i, x, y);
		}
	}
}

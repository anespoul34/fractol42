/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 12:47:35 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/25 12:12:01 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_color_menger(t_env *e, int x, int y, int i)
{
	t_color	*color;
	int		p;

	color = get_menger_color(i);
	p = x * 4 + y * e->sl;
	if (check_for_x_y(x, y, e))
	{
		e->men->img[p] = color->b;
		e->men->img[p + 1] = color->g;
		e->men->img[p + 2] = color->r;
	}
}

void		draw_menger_up(int x, int y, int a, t_env *e)
{
	int		i;
	int		b;
	t_point c;
	t_point d;

	b = a + x;
	i = 2;
	c.x = x;
	c.y = y;
	d.x = x + a / 3;
	d.y = y - a / 3;
	while (c.x <= b)
	{
		menger_line(c, d, e, i);
		c.x++;
		d.x++;
	}
}

void		draw_menger_right(int x, int y, int a, t_env *e)
{
	int		i;
	int		b;
	t_point c;
	t_point d;

	b = a + y;
	i = 3;
	c.x = x;
	c.y = y;
	d.x = x + a / 3;
	d.y = y - a / 3;
	while (c.y <= b)
	{
		menger_line(c, d, e, i);
		c.y++;
		d.y++;
	}
}

void		draw_menger_face(int x, int y, int a, t_env *e)
{
	int		i;
	int		b;
	t_point c;
	t_point d;

	b = a + x;
	i = 1;
	c.x = x;
	c.y = y;
	d.x = x;
	d.y = y + a;
	while (c.x <= b)
	{
		menger_line(c, d, e, i);
		c.x++;
		d.x++;
	}
}

void		draw_menger(int x, int y, int a, t_env *e)
{
	draw_menger_face(x, y, a, e);
	draw_menger_right(x + a, y, a, e);
	draw_menger_up(x, y, a, e);
}

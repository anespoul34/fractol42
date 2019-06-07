/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 12:37:02 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/15 18:47:34 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_color_carpet(t_env *e, int x, int y)
{
	t_color *color;
	int		p;

	color = get_sierp_color(e);
	p = x * 4 + y * e->sl;
	if (check_for_x_y(x, y, e) && !e->carp->img[p])
	{
		e->carp->img[p] = color->b;
		e->carp->img[p + 1] = color->g;
		e->carp->img[p + 2] = color->r;
	}
}

void		ft_draw_carpet_line(t_point p1, t_point p2, t_env *e)
{
	t_point d;
	t_point s;
	int		err;
	int		e2;

	d.x = ABS(p2.x - p1.x);
	d.y = ABS(p2.y - p1.y);
	s.x = p1.x < p2.x ? 1 : -1;
	s.y = p1.y < p2.y ? 1 : -1;
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (42)
	{
		draw_color_carpet(e, p1.x, p1.y);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = err;
		if (e2 > -d.x && ((err -= d.y) || !err))
			p1.x += s.x;
		if (e2 < d.y)
		{
			err += d.x;
			p1.y += s.y;
		}
	}
}

void		cube(int x, int y, int a, t_env *e)
{
	t_point c;
	t_point d;
	t_point f;
	t_point g;

	c.x = x;
	c.y = y;
	d.x = x;
	d.y = y + a;
	f.x = x + a;
	f.y = y + a;
	g.x = x + a;
	g.y = y;
	ft_draw_carpet_line(c, d, e);
	ft_draw_carpet_line(c, g, e);
	ft_draw_carpet_line(f, g, e);
	ft_draw_carpet_line(f, d, e);
}

t_point		new_point(t_point p, int a, int id)
{
	if (id < 3)
	{
		p.x = p.x - (a * 2) / 3 + id * a;
		p.y = p.y - (a / 3) * 2;
	}
	if (id == 3)
	{
		p.x = p.x - (a / 3) * 2;
		p.y = p.y + a / 3;
	}
	if (id == 4)
	{
		p.x = p.x + a + a / 3;
		p.y = p.y + a / 3;
	}
	if (id >= 5 && id < 8)
	{
		p.x = p.x - (a * 2) / 3 + (id - 5) * a;
		p.y = p.y + (a / 3) * 4;
	}
	return (p);
}

void		carpet(t_env *e, t_point p, int a, int i)
{
	if (i > 0)
	{
		cube(p.x, p.y, a, e);
		carpet(e, new_point(p, a, 0), a / 3, i - 1);
		carpet(e, new_point(p, a, 1), a / 3, i - 1);
		carpet(e, new_point(p, a, 2), a / 3, i - 1);
		carpet(e, new_point(p, a, 3), a / 3, i - 1);
		carpet(e, new_point(p, a, 4), a / 3, i - 1);
		carpet(e, new_point(p, a, 5), a / 3, i - 1);
		carpet(e, new_point(p, a, 6), a / 3, i - 1);
		carpet(e, new_point(p, a, 7), a / 3, i - 1);
	}
}

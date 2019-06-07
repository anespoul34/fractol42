/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 18:35:54 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/22 16:59:48 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		menger_line(t_point p1, t_point p2, t_env *e, int i)
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
		draw_color_menger(e, p1.x, p1.y, i);
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

t_point		n_p(int x, int y, int a, int i)
{
	t_point	p;

	if (i < 3)
	{
		x += ((a / 3) * i);
		y += ((a / 3) * 3);
	}
	if (i >= 3 && i <= 5)
	{
		x += (a / 3) * (i - 3);
		y += (a / 3) * 2;
	}
	if (i >= 6)
	{
		x += (a / 3) * (i - 6);
		y += (a / 3);
	}
	p.x = x;
	p.y = y - (a / 3);
	return (p);
}

void		menger(t_env *e, t_point p, int a, int i)
{
	if (i == 0)
		draw_menger(p.x, p.y, a, e);
	if (i > 0)
	{
		menger(e, n_p(p.x + a * 2 / 9, p.y - a * 2 / 9, a, 0), a / 3, i - 1);
		menger(e, n_p(p.x + a * 2 / 9, p.y - a * 2 / 9, a, 1), a / 3, i - 1);
		menger(e, n_p(p.x + a * 2 / 9, p.y - a * 2 / 9, a, 2), a / 3, i - 1);
		menger(e, n_p(p.x + a * 2 / 9, p.y - a * 2 / 9, a, 3), a / 3, i - 1);
		menger(e, n_p(p.x + a * 2 / 9, p.y - a * 2 / 9, a, 5), a / 3, i - 1);
		menger(e, n_p(p.x + a * 2 / 9, p.y - a * 2 / 9, a, 6), a / 3, i - 1);
		menger(e, n_p(p.x + a * 2 / 9, p.y - a * 2 / 9, a, 7), a / 3, i - 1);
		menger(e, n_p(p.x + a * 2 / 9, p.y - a * 2 / 9, a, 8), a / 3, i - 1);
		menger(e, n_p(p.x + a / 9, p.y - a / 9, a, 0), a / 3, i - 1);
		menger(e, n_p(p.x + a / 9, p.y - a / 9, a, 2), a / 3, i - 1);
		menger(e, n_p(p.x + a / 9, p.y - a / 9, a, 6), a / 3, i - 1);
		menger(e, n_p(p.x + a / 9, p.y - a / 9, a, 8), a / 3, i - 1);
		menger(e, n_p(p.x, p.y, a, 0), a / 3, i - 1);
		menger(e, n_p(p.x, p.y, a, 1), a / 3, i - 1);
		menger(e, n_p(p.x, p.y, a, 2), a / 3, i - 1);
		menger(e, n_p(p.x, p.y, a, 3), a / 3, i - 1);
		menger(e, n_p(p.x, p.y, a, 5), a / 3, i - 1);
		menger(e, n_p(p.x, p.y, a, 6), a / 3, i - 1);
		menger(e, n_p(p.x, p.y, a, 7), a / 3, i - 1);
		menger(e, n_p(p.x, p.y, a, 8), a / 3, i - 1);
	}
}

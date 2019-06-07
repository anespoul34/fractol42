/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cantor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 14:50:57 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/15 17:09:52 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_color_circle(t_env *e, int x, int y)
{
	t_color *color;
	int		p;

	color = get_sierp_color(e);
	p = x * 4 + y * e->sl;
	if (check_for_x_y(x, y, e) && !e->ci->img[p])
	{
		e->ci->img[p] = color->b;
		e->ci->img[p + 1] = color->g;
		e->ci->img[p + 2] = color->r;
	}
}

void		draw(t_point p, int i, int j, t_env *e)
{
	draw_color_circle(e, p.x + i, p.y + j);
	draw_color_circle(e, p.x + j, p.y + i);
	draw_color_circle(e, p.x + i, HEIGHT - j - p.y);
	draw_color_circle(e, p.x + j, WIDTH - i - p.y);
	draw_color_circle(e, WIDTH - i - p.x, j + p.y);
	draw_color_circle(e, HEIGHT - j - p.x, i + p.y);
	draw_color_circle(e, WIDTH - i - p.x, HEIGHT - j - p.y);
	draw_color_circle(e, HEIGHT - j - p.x, WIDTH - i - p.y);
}

void		draw_circle(t_point p, int r, t_env *e)
{
	int d;
	int i;
	int j;

	i = 0;
	j = r;
	d = 1 - r;
	draw(p, i, j, e);
	while (j > i)
	{
		if (d < 0)
			d += 2 * i + 3;
		else
		{
			d += 2 * (i - j) + 5;
			j--;
		}
		i++;
		draw(p, i, j, e);
	}
}

t_point		new_p_cant(t_point p, int a, int b)
{
	if (b == 1)
		p.x -= a;
	if (b == 2)
		p.x += a;
	if (b == 3)
		p.y -= a;
	if (b == 4)
		p.y += a;
	return (p);
}

void		circle(t_env *e, t_point p, int r, int i)
{
	if (i > 0)
	{
		draw_circle(p, r, e);
		circle(e, new_p_cant(p, r, 1), r / 2, i - 1);
		circle(e, new_p_cant(p, r, 2), r / 2, i - 1);
		circle(e, new_p_cant(p, r, 3), r / 2, i - 1);
		circle(e, new_p_cant(p, r, 4), r / 2, i - 1);
	}
}

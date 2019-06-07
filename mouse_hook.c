/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 15:57:48 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/25 12:43:21 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		move_c(int x, int y, t_env *e)
{
	double	x2;
	double	y2;

	if (e->j->move % 2 != 0)
	{
		if (x <= WIDTH && y <= HEIGHT)
		{
			x2 = x / e->j->zoom_x + e->j->x1;
			y2 = y / e->j->zoom_y + e->j->y1;
			e->j->c_r = x2;
			e->j->c_i = y2;
			expose_hook(e);
			return (1);
		}
	}
	return (0);
}

int		julia_mouse_events(int button, int x, int y, t_env *e)
{
	double			x2;
	double			y2;

	x2 = x / e->j->zoom_x + e->j->x1;
	y2 = y / e->j->zoom_y + e->j->y1;
	if (button == 2 || button == WHEEL_DOWN)
		e->j->k /= 0.5;
	e->j->x2 = x2 + e->j->k;
	e->j->x1 = x2 - e->j->k;
	e->j->y2 = y2 + e->j->k;
	e->j->y1 = y2 - e->j->k;
	e->j->i_max += 4;
	if (button == 1 || button == WHEEL_UP)
		e->j->k *= 0.5;
	e->j->zoom_x = e->img_x / (e->j->x2 - e->j->x1);
	e->j->zoom_y = e->img_y / (e->j->y2 - e->j->y1);
	expose_hook(e);
	return (0);
}

int		mouse_events(int button, int x, int y, t_env *e)
{
	double			x2;
	double			y2;

	x2 = x / e->m->zoom_x + e->m->x1;
	y2 = y / e->m->zoom_y + e->m->y1;
	if (button == 2 || button == WHEEL_DOWN)
		e->m->k /= 0.5;
	e->m->x2 = x2 + e->m->k;
	e->m->x1 = x2 - e->m->k;
	e->m->y2 = y2 + e->m->k;
	e->m->y1 = y2 - e->m->k;
	e->m->i_max += 10;
	if (button == 1 || button == WHEEL_UP)
		e->m->k *= 0.5;
	e->m->zoom_x = WIDTH / (e->m->x2 - e->m->x1);
	e->m->zoom_y = HEIGHT / (e->m->y2 - e->m->y1);
	expose_hook(e);
	return (0);
}

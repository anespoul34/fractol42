/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 15:47:40 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/25 12:36:24 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandel_pos(int key, t_env *e)
{
	if (key == UP)
		e->m->y1 -= 0.78 * 2 / e->m->i_max;
	if (key == DOWN)
		e->m->y1 += 0.78 * 2 / e->m->i_max;
	if (key == RIGHT)
		e->m->x1 += 0.78 * 2 / e->m->i_max;
	if (key == LEFT)
		e->m->x1 -= 0.78 * 2 / e->m->i_max;
}

void	julia_pos(int key, t_env *e)
{
	if (key == UP)
		e->j->y1 -= 0.78 * 2 / e->j->i_max;
	if (key == DOWN)
		e->j->y1 += 0.78 * 2 / e->j->i_max;
	if (key == RIGHT)
		e->j->x1 += 0.78 * 2 / e->j->i_max;
	if (key == LEFT)
		e->j->x1 -= 0.78 * 2 / e->j->i_max;
}

int		mandel_key_events(int key, t_env *e)
{
	mandel_pos(key, e);
	if (key == ESC)
		exit(0);
	if (key == KEY_C)
	{
		e->c++;
		if (e->c > 5)
			e->c = 1;
	}
	if (key == KEY_R)
		init_mandel(e->m, e);
	expose_hook(e);
	return (0);
}

int		julia_key_events(int key, t_env *e)
{
	julia_pos(key, e);
	if (key == 46)
		e->j->move++;
	if (key == KEY_C)
	{
		e->c++;
		if (e->c > 5)
			e->c = 1;
	}
	if (key == KEY_R)
		init_julia(e->j, e);
	if (key == ESC)
		exit(0);
	expose_hook(e);
	return (0);
}

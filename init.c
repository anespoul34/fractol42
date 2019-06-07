/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 13:48:33 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/25 12:41:04 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_mandel(t_mandel *m, t_env *e)
{
	if (m->win == NULL)
	{
		if (!(m->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Mandelbrot")))
			return (0);
	}
	m->i_max = 70;
	m->x1 = -2.1;
	m->x2 = 0.6;
	m->y1 = -1.2;
	m->y2 = 1.2;
	m->z_r = 0;
	m->z_i = 0;
	m->zoom_x = e->img_x / (m->x2 - m->x1);
	m->zoom_y = e->img_y / (m->y2 - m->y1);
	m->img_ptr = NULL;
	m->img = NULL;
	m->k = 0.78;
	return (1);
}

int		init_julia(t_julia *j, t_env *e)
{
	if (j->win == NULL)
	{
		if (!(j->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Julia")))
			return (0);
	}
	j->move = 0;
	j->i_max = 150;
	j->x1 = -1;
	j->x2 = 1;
	j->y1 = -1.2;
	j->y2 = 1.2;
	j->c_r = 0.285;
	j->c_i = 0.01;
	j->zoom_x = e->img_x / (j->x2 - j->x1);
	j->zoom_y = e->img_y / (j->y2 - j->y1);
	j->img_ptr = NULL;
	j->img = NULL;
	j->k = 0.78;
	return (1);
}

int		check_init(t_env *e)
{
	if (e->mandel && init_mandel(e->m, e) == 0)
		return (0);
	if (e->sierp && init_sierp(e->s, e) == 0)
		return (0);
	if (e->carpet && init_carpet(e->carp, e) == 0)
		return (0);
	if (e->circle && init_circle(e->ci, e) == 0)
		return (0);
	if (e->julia && init_julia(e->j, e) == 0)
		return (0);
	if (e->menger && init_menger(e->men, e) == 0)
		return (0);
	return (1);
}

int		init_env(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (0);
	e->img_x = WIDTH;
	e->img_y = HEIGHT;
	e->c = 1;
	e->men = (t_menger *)malloc(sizeof(t_menger));
	e->m = (t_mandel *)malloc(sizeof(t_mandel));
	e->s = (t_sierp *)malloc(sizeof(t_sierp));
	e->carp = (t_carpet *)malloc(sizeof(t_carpet));
	e->ci = (t_circle *)malloc(sizeof(t_circle));
	e->j = (t_julia *)malloc(sizeof(t_julia));
	e->men->win = NULL;
	e->s->win = NULL;
	e->j->win = NULL;
	e->carp->win = NULL;
	e->ci->win = NULL;
	e->m->win = NULL;
	if (!e->s || !e->carp || !e->ci || !e->m || !e->j || !e->men)
		return (0);
	return (check_init(e));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 14:08:20 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/22 17:19:32 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	expose_or_handle_sierp(t_env *e, int i)
{
	if (i == 1)
	{
		sierp(e, e->s->p, e->s->a, e->s->i);
		mlx_put_image_to_window(e->mlx, e->s->win, e->s->img_ptr, 0, 0);
		carpet(e, e->carp->p, e->carp->a, e->carp->i);
		mlx_put_image_to_window(e->mlx, e->carp->win, e->carp->img_ptr, 0, 0);
		circle(e, e->ci->p, e->ci->a, e->ci->i);
		mlx_put_image_to_window(e->mlx, e->ci->win, e->ci->img_ptr, 0, 0);
	}
	else
	{
		mlx_key_hook(e->s->win, sierp_key_events, e);
		mlx_expose_hook(e->s->win, expose_hook, e);
		mlx_key_hook(e->carp->win, carp_key_events, e);
		mlx_expose_hook(e->carp->win, expose_hook, e);
		mlx_key_hook(e->ci->win, circle_key_events, e);
		mlx_expose_hook(e->ci->win, expose_hook, e);
	}
}

int		expose_hook(t_env *e)
{
	create_image(e);
	if (e->sierp)
		expose_or_handle_sierp(e, 1);
	if (e->menger)
	{
		menger(e, e->men->p, e->men->a, e->men->i);
		mlx_put_image_to_window(e->mlx, e->men->win, e->men->img_ptr, 0, 0);
	}
	if (e->mandel)
	{
		mandel(e);
		mlx_put_image_to_window(e->mlx, e->m->win, e->m->img_ptr, 0, 0);
	}
	if (e->julia)
	{
		julia(e);
		mlx_put_image_to_window(e->mlx, e->j->win, e->j->img_ptr, 0, 0);
	}
	ft_clean(e);
	return (0);
}

void	handle_fractal(t_env *e)
{
	if (e->menger)
	{
		mlx_key_hook(e->men->win, menger_key_events, e);
		mlx_expose_hook(e->men->win, expose_hook, e);
	}
	if (e->mandel)
	{
		mlx_key_hook(e->m->win, mandel_key_events, e);
		mlx_mouse_hook(e->m->win, mouse_events, e);
		mlx_expose_hook(e->m->win, expose_hook, e);
	}
	if (e->julia)
	{
		mlx_key_hook(e->j->win, julia_key_events, e);
		mlx_mouse_hook(e->j->win, julia_mouse_events, e);
		mlx_expose_hook(e->j->win, expose_hook, e);
		mlx_hook(e->j->win, 6, (1L << 6), move_c, e);
	}
	if (e->sierp)
		expose_or_handle_sierp(e, 0);
}

void	ft_draw_line(t_point p1, t_point p2, t_env *e)
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
		draw_color_sierp(e, p1.x, p1.y);
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

int		create_image(t_env *e)
{
	if (!e->s->img || !e->carp->img || !e->ci->img || !e->m->img || !e->j->img \
			|| !e->men->img)
	{
		e->end = 0;
		e->bpp = 8;
		e->sl = WIDTH;
		e->s->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->carp->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->ci->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->m->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->j->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		e->men->img_ptr = mlx_new_image(e->mlx, WIDTH, HEIGHT);
		if (!e->s->img_ptr || !e->carp->img_ptr || !e->ci->img_ptr || \
				!e->m->img_ptr || !e->j->img_ptr || !e->men->img_ptr)
			ft_error(-1);
		e->men->img = IMGAD(e->men->img_ptr, &(e->bpp), &(e->sl), &(e->end));
		e->j->img = IMGAD(e->j->img_ptr, &(e->bpp), &(e->sl), &(e->end));
		e->s->img = IMGAD(e->s->img_ptr, &(e->bpp), &(e->sl), &(e->end));
		e->carp->img = IMGAD(e->carp->img_ptr, &(e->bpp), &(e->sl), &(e->end));
		e->ci->img = IMGAD(e->ci->img_ptr, &(e->bpp), &(e->sl), &(e->end));
		e->m->img = IMGAD(e->m->img_ptr, &(e->bpp), &(e->sl), &(e->end));
		return (1);
	}
	return (0);
}

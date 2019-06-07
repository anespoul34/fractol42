/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sierp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:02:03 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/21 17:25:20 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_sierp(t_sierp *s, t_env *e)
{
	if (s->win == NULL)
	{
		if (!(s->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Sierpinski")))
			return (0);
	}
	s->x = WIDTH / 2 - 400;
	s->y = HEIGHT - 100;
	s->a = 800;
	s->i = 3;
	s->p.x = s->x;
	s->p.y = s->y;
	s->img_ptr = NULL;
	s->img = NULL;
	return (1);
}

int		init_carpet(t_carpet *carp, t_env *e)
{
	if (carp->win == NULL)
	{
		if (!(carp->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Carpet")))
			return (0);
	}
	carp->x = WIDTH / 3;
	carp->y = HEIGHT / 3;
	carp->a = carp->x;
	carp->i = 1;
	carp->p.x = carp->x;
	carp->p.y = carp->y;
	carp->img_ptr = NULL;
	carp->img = NULL;
	return (1);
}

int		init_circle(t_circle *ci, t_env *e)
{
	if (ci->win == NULL)
	{
		if (!(ci->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Circle")))
			return (0);
	}
	ci->x = WIDTH / 2;
	ci->y = HEIGHT / 2;
	ci->i = 1;
	ci->a = 300;
	ci->p.x = ci->x;
	ci->p.y = ci->y;
	ci->img_ptr = NULL;
	ci->img = NULL;
	return (1);
}

int		init_menger(t_menger *men, t_env *e)
{
	if (men->win == NULL)
	{
		if (!(men->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "Menger")))
			return (0);
	}
	men->x = WIDTH / 3;
	men->y = HEIGHT / 3;
	men->i = 0;
	men->a = men->x;
	men->p.x = men->x;
	men->p.y = men->y;
	men->img_ptr = NULL;
	men->img = NULL;
	return (1);
}

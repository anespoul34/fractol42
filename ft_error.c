/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:50:50 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/15 19:00:05 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int error)
{
	if (error == -1)
		exit(0);
	if (error == 0)
	{
		ft_putendl("No valid argument !");
		ft_putstr("Choose your fractal :");
		ft_putendl(" Julia, Mandelbrot, Sierpinski, Menger.");
	}
	exit(0);
}

int		check_for_x_y(int x, int y, t_env *e)
{
	if (x <= 0 || x >= WIDTH)
		return (0);
	if (y <= 0 || y >= HEIGHT)
		return (0);
	if (x * 4 + y * e->sl > WIDTH * 4 + HEIGHT * e->sl)
		return (0);
	return (1);
}

void	init_all(t_env *e)
{
	e->sierp = 0;
	e->carpet = 0;
	e->circle = 0;
	e->mandel = 0;
	e->julia = 0;
	e->menger = 0;
}

int		check_av(int ac, char **av, t_env *e)
{
	int i;
	int c;

	i = 0;
	c = 0;
	init_all(e);
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "Menger") == 0)
			e->menger = 1;
		if (ft_strcmp(av[i], "Sierpinski") == 0)
		{
			e->circle = 1;
			e->carpet = 1;
			e->sierp = 1;
		}
		if (ft_strcmp(av[i], "Mandelbrot") == 0)
			e->mandel = 1;
		if (ft_strcmp(av[i], "Julia") == 0)
			e->julia = 1;
		if (e->sierp || e->carpet || e->circle || e->mandel || e->julia ||\
				e->menger)
			c++;
	}
	return (c);
}

void	ft_clean(t_env *e)
{
	int		p;

	p = -1;
	while (++p < WIDTH * 4 + HEIGHT * e->sl)
	{
		e->men->img[p] = 0;
		e->m->img[p] = 0;
		e->j->img[p] = 0;
		e->ci->img[p] = 0;
		e->s->img[p] = 0;
		e->carp->img[p] = 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 15:40:53 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/15 19:37:19 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

t_color		*get_menger_color(int i)
{
	t_color *color;

	color = malloc(sizeof(t_color));
	init_color(color);
	if (i == 1)
	{
		color->r = 255;
		color->g = 255;
		color->b = 255;
	}
	if (i == 2)
	{
		color->r = 255;
		color->g = 150;
	}
	if (i == 3)
		color->r = 255;
	return (color);
}

t_color		*get_sierp_color(t_env *e)
{
	t_color *color;

	color = malloc(sizeof(t_color));
	init_color(color);
	if (e->c == 1)
		color->r = 255;
	if (e->c == 2)
		color->g = 255;
	if (e->c == 3)
		color->b = 255;
	if (e->c == 4)
	{
		color->r = 255;
		color->b = 144;
	}
	if (e->c == 5)
	{
		color->r = 255;
		color->g = 240;
	}
	return (color);
}

t_color		*more_color(int b, t_env *e, t_color *color)
{
	if (e->c == 3)
	{
		color->b = 50;
		color->r = b;
		color->g = 102;
	}
	if (e->c == 4)
	{
		color->b = 255 - b;
		color->r = 255 - b / 3;
		color->g = 255 - b / 2;
	}
	if (e->c == 5)
	{
		color->r = 255;
		color->g = b;
		color->b = 0;
	}
	return (color);
}

t_color		*get_color(int i, int imax, t_env *e)
{
	t_color *color;
	int		a;
	int		b;

	color = malloc(sizeof(t_color));
	a = i * 255 / imax;
	b = i * 255 / 30;
	init_color(color);
	if (e->c == 1)
	{
		color->r = 0;
		color->g = b;
		color->b = 255;
	}
	if (e->c == 2)
	{
		color->g = a;
		color->b = a;
		color->r = b;
	}
	else
		color = more_color(b, e, color);
	return (color);
}

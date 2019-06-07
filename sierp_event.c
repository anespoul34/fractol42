/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierp_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 15:41:19 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/22 16:07:10 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		menger_key_events(int key, t_env *e)
{
	menger_pos(key, e);
	if (key == ESC)
		exit(0);
	if (key == KEY_C)
	{
		e->c++;
		if (e->c > 5)
			e->c = 1;
	}
	if (key == KEY_I)
	{
		ft_clean(e);
		e->men->i++;
		if (e->men->i > 5)
			init_menger(e->men, e);
	}
	if (key == KEY_R)
		init_menger(e->men, e);
	expose_hook(e);
	return (0);
}

int		carp_key_events(int key, t_env *e)
{
	carpet_pos(key, e);
	if (key == ESC)
		exit(0);
	if (key == KEY_C)
	{
		e->c++;
		if (e->c > 5)
			e->c = 1;
	}
	if (key == KEY_I)
	{
		e->carp->i++;
		if (e->carp->i > 12)
			e->carp->i = 12;
	}
	if (key == KEY_R)
		init_carpet(e->carp, e);
	expose_hook(e);
	return (0);
}

int		circle_key_events(int key, t_env *e)
{
	circle_pos(key, e);
	if (key == ESC)
		exit(0);
	if (key == KEY_C)
	{
		e->c++;
		if (e->c > 5)
			e->c = 1;
	}
	if (key == KEY_I)
	{
		e->ci->i++;
		if (e->ci->i > 12)
			e->ci->i = 12;
	}
	if (key == KEY_R)
		init_circle(e->ci, e);
	expose_hook(e);
	return (0);
}

int		sierp_key_events(int key, t_env *e)
{
	sierp_pos(key, e);
	if (key == ESC)
		exit(0);
	if (key == KEY_C)
	{
		e->c++;
		if (e->c > 5)
			e->c = 1;
	}
	if (key == KEY_I)
	{
		e->s->i++;
		if (e->s->i > 12)
			e->s->i = 12;
	}
	if (key == KEY_R)
		init_sierp(e->s, e);
	expose_hook(e);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 13:44:04 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/25 12:21:13 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menger_pos(int key, t_env *e)
{
	if (key == 78)
		e->men->a /= 2;
	if (key == 69)
		e->men->a = e->men->a + e->men->a / 2;
	if (key == UP)
		e->men->p.y -= e->men->a;
	if (key == DOWN)
		e->men->p.y += e->men->a;
	if (key == RIGHT)
		e->men->p.x += e->men->a;
	if (key == LEFT)
		e->men->p.x -= e->men->a;
}

void	carpet_pos(int key, t_env *e)
{
	if (key == 78)
		e->carp->a /= 2;
	if (key == 69)
		e->carp->a = e->carp->a + e->carp->a / 2;
	if (key == UP)
		e->carp->p.y -= 100;
	if (key == DOWN)
		e->carp->p.y += 100;
	if (key == RIGHT)
		e->carp->p.x += 100;
	if (key == LEFT)
		e->carp->p.x -= 100;
}

void	circle_pos(int key, t_env *e)
{
	if (key == 78)
		e->ci->a /= 2;
	if (key == 69)
		e->ci->a = e->ci->a + e->ci->a / 2;
	if (key == UP)
		e->ci->p.y -= 100;
	if (key == DOWN)
		e->ci->p.y += 100;
	if (key == RIGHT)
		e->ci->p.x += 100;
	if (key == LEFT)
		e->ci->p.x -= 100;
}

void	sierp_pos(int key, t_env *e)
{
	if (key == 78)
		e->s->a /= 2;
	if (key == 69)
		e->s->a = e->s->a + e->s->a / 2;
	if (key == UP)
		e->s->p.y -= 100;
	if (key == DOWN)
		e->s->p.y += 100;
	if (key == RIGHT)
		e->s->p.x += 100;
	if (key == LEFT)
		e->s->p.x -= 100;
}

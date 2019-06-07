/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 12:37:48 by anespoul          #+#    #+#             */
/*   Updated: 2016/04/25 12:28:40 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_env *e;

	if (ac < 2 || ac > 5)
		ft_error(0);
	e = (t_env *)malloc(sizeof(t_env));
	if (!(check_av(ac, av, e)))
		ft_error(0);
	if (!(init_env(e)))
		return (0);
	handle_fractal(e);
	mlx_loop(e->mlx);
	return (0);
}

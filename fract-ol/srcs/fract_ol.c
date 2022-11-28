/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 03:16:36 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/28 02:21:33 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	mouse_hook(int keycode, t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	return (0);
}

t_vars	init_window(char *title, t_vars vars)
{
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	// if escape is pressed, close the window
	mlx_hook(vars.win, 2, 1L<<0, mouse_hook, &vars);
	mandelbrot(vars);
	return (vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
	{
		printf("Usage: ./fractol [fractal name]\n");
		return (0);
	}
	vars = init_window(argv[1], vars);
	mlx_loop(vars.mlx);
	return (0);
}

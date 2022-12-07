/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 03:16:36 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/07 05:35:08 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

/*
* init_vars
*/
void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->window_width = 800;
	vars->window_height = 600;
	vars->mlx_win = mlx_new_window(vars->mlx, vars->window_width, vars->window_height, "fract_ol");
	vars->zoom = 1;
	vars->x_screen = 0;
	vars->y_screen = 0;
	vars->re = 0;
	vars->im = 0;
	vars->move_x = 0;
	vars->move_y = 0;
	vars->max_iter = 60;
}

int	zoom(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
		vars->zoom *= 1.1;
	else if (button == 5)
		vars->zoom /= 1.1;
	vars->move_x = (x - vars->window_width / 2) / (2 * vars->zoom * vars->window_width) + vars->move_x;
	vars->move_y = (y - vars->window_height / 2) / (2 * vars->zoom * vars->window_height) + vars->move_y;
	fractal(vars, vars->max_iter);
	return (0);
}

/*
* init_fract
*/
void	init_window(char *arg)
{
	t_vars	vars;

	(void)arg;
	init_vars(&vars);
	if (ft_strcmp(arg, "mandelbrot") == 0)
		vars.type = 0;
	else if (ft_strcmp(arg, "julia") == 0)
		vars.type = 1;
	else if (ft_strcmp(arg, "burningship") == 0)
		vars.type = 2;
	else if (ft_strcmp(arg, "bouda") == 0)
		vars.type = 3;
	else
	{
		ft_putstr_fd("Erro\nUsage: ./fract_ol [fractal_name]\nAvailable fractals: mandelbrot, julia\n", 1);
		exit(0);
	}
	// vars.addr = mlx_get_data_addr(vars.img, &pixel_bits, &line_size, &endian);
	mlx_hook(vars.mlx_win, 4, 1L << 2, zoom, &vars);
	mlx_hook(vars.mlx_win, 5, 1L << 3, zoom, &vars);
	input_vars(&vars);
	fractal(&vars, vars.max_iter);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		init_window(argv[1]);
	else
		ft_putstr_fd("Erro\nUsage: ./fract_ol [fractal_name]\nAvailable fractals: mandelbrot, julia\n", 1);
	return (0);
}

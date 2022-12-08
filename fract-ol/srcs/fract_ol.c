/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 03:16:36 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/08 18:15:17 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

/*
* init_vars
*/
void	init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->window_width = 1920;
	vars->window_height = 1440;
	vars->mlx_win = mlx_new_window(vars->mlx, vars->window_width,
			vars->window_height, "fract_ol");
	vars->zoom = 1;
	vars->x_screen = 0;
	vars->y_screen = 0;
	vars->move_x = 0;
	vars->move_y = 0;
	vars->re = 0;
	vars->im = 0;
	vars->max_iter = 60;
	vars->img = mlx_new_image(vars->mlx, vars->window_width,
			vars->window_height);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
}

int	zoom(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
		vars->zoom *= 1.1;
	else if (button == 5)
		vars->zoom /= 1.1;
	vars->move_x = (x - vars->window_width / 2)
		/ (3 * vars->zoom * vars->window_width) + vars->move_x;
	vars->move_y = (y - vars->window_height / 2)
		/ (3 * vars->zoom * vars->window_height) + vars->move_y;
	fractal(vars);
	return (0);
}

int	reaload_window(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->mlx_win);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
	return (0);
}

void	redefine_vars(t_vars *vars, char **argv, int argc)
{
	vars->type = 1;
	if (argc == 2)
	{
		vars->im = 0;
		vars->re = -1.546;
	}
	else
	{
		vars->re = ft_atof(argv[2]);
		vars->im = ft_atof(argv[3]);
	}
}
/*
* init_fract
*/
void	init_window(char **argv, int argc)
{
	t_vars	vars;

	init_vars(&vars);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		vars.type = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		redefine_vars(&vars, argv, argc);
	else if (ft_strcmp(argv[1], "burningship") == 0)
		vars.type = 2;
	else
	{
		ft_putstr_fd("Erro\nUsage: ./fract_ol [fractal_name]\n\
			Available fractals: mandelbrot, julia\n", 1);
		exit(0);
	}
	mlx_hook(vars.mlx_win, 4, 1L << 2, zoom, &vars);
	// mlx_hook(vars.mlx_win, 17, 1L << 17, reaload_window, &vars);
	mlx_hook(vars.mlx_win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.mlx_win, 17, 1L << 17, close_window, &vars);
	fractal(&vars);
	mlx_loop(vars.mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2 || argc == 4)
		init_window(argv, argc);
	else
		ft_putstr_fd("\t------Error------\n\
			Usage: ./fract_ol [fractal_name]\nAvailable fractals: mandelbrot\
			, julia, burningship\n", 1);
	return (0);
}

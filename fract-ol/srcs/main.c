/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:57:31 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/09 20:49:11 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

bool	print_param(void)
{
	ft_putstr("Usage: ./fractol [SECTION]\n\tmandelbrot\tz² + c \
		\n\tjulia\t\tz² - 1.4\n\tburningship\tz² + abs(c)\n");
	return (false);
}

bool	init(t_vars *vars, t_complex tmp, int fractal_type)
{
	vars->mlx_ptr = mlx_init();
	if (!vars->mlx_ptr)
		return (false);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIN_HEIGHT, WIN_WIDTH, \
		"fractol");
	if (!vars->win_ptr)
		return (false);
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, WIN_HEIGHT, WIN_WIDTH);
	vars->addr = mlx_get_data_addr(vars->img_ptr, &vars->bits_per_pixel, \
		&vars->line_length, &vars->endian);
	vars->zoom = 0.5;
	vars->max_iter = 70;
	vars->window_pos.x = 0;
	vars->window_pos.y = 0;
	vars->c.re = tmp.re;
	vars->c.im = tmp.im;
	vars->move.re = 0;
	vars->move.im = 0;
	vars->type = fractal_type;
	return (true);
}

void	start(t_vars *vars)
{
	mlx_hook(vars->win_ptr, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win_ptr, 4, 1L << 2, mouse_hook, vars);
	mlx_hook(vars->win_ptr, 17, 1L << 17, close_window, vars);
	fractal(vars);
	mlx_loop(vars->mlx_ptr);
	mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
}

bool	set_input(int argc, char **argv, t_vars *vars)
{
	bool	edit;

	edit = false;
	if (argc < 2 || argc > 5)
		return (print_param());
	if ((argc == 2 || argc == 3) && !ft_strcmp(argv[1], "mandelbrot"))
		edit = init(vars, (t_complex){0.0, 0.0}, 0);
	if ((argc == 2 || argc == 3) && !ft_strcmp(argv[1], "burningship"))
		edit = init(vars, (t_complex){0.0, 0.0}, 2);
	if (argc == 3 && ft_atoi(argv[2]) && edit)
		vars->max_iter = ft_atoi(argv[2]);
	else if ((argc >= 2 && argc <= 5) && !ft_strcmp(argv[1], "julia"))
		edit = set_julia(argc, argv, vars);
	else
		return (print_param());
	return (true);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (check_argv(argc, argv, &vars))
		start(&vars);
	return (0);
}

/*
1 arg:
	- mandelbrot
		- option iter max ?
	- burningship
		- option iter max ?
	- julia
		- option nombre 1 ?
		- option nombre 2 ?
		- option iter max ?
*/
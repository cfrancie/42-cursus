/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:57:31 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/06 20:41:00 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	print_param(void)
{
	ft_putstr("Usage: ./fractol [SECTION]\n\tmandelbrot\tz² + c \
		\n\tjulia\t\tz² - 1.4\n\tburning_ship\tz² + abs(c)\n");
}

void	init_vars(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, WIN_HEIGHT, WIN_WIDTH, \
		"fractol");
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, WIN_HEIGHT, WIN_WIDTH);
	vars->addr = mlx_get_data_addr(vars->img_ptr, &vars->bits_per_pixel, \
		&vars->line_length, &vars->endian);
	vars->zoom = 1;
	vars->max_iter = 70;
	vars->window_pos.x = 0;
	vars->window_pos.y = 0;
	vars->c.re = -0.7;
	vars->c.im = 0.27015;
	vars->move.re = 0;
	vars->move.im = 0;
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

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc < 2 || argc >= 3)
	{
		print_param();
		return (0);
	}
	init_vars(&vars);
	if (!ft_strcmp(argv[1], "mandelbrot"))
		vars.type = 0;
	else if (!ft_strcmp(argv[1], "julia"))
		vars.type = 1;
	else if (!ft_strcmp(argv[1], "burning_ship"))
		vars.type = 2;
	else if (argc == 3)
	{
		vars.type = 3;
		vars.c.re = ft_atof(argv[2]);
		vars.c.im = ft_atof(argv[3]);
	}
	start(&vars);
	return (0);
}

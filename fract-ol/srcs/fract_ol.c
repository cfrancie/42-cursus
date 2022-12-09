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

void	init_vars(t_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, HEIGHT, WIDTH, "fract_ol");
	vars->zoom = 1;
	vars->screen.x = 0;
	vars->screen.y = 0;
	vars->move.re_x = 0;
	vars->move.im_y = 0;
	vars->comp.re_x = 0.285;
	vars->comp.im_y = 0.013;
	vars->max_iter = 70;
	vars->img_ptr = mlx_new_image(vars->mlx_ptr, WIDTH,HEIGHT);
	vars->addr_ptr = mlx_get_data_addr(vars->img_ptr, &vars->bits_per_pixel,&vars->line_length, &vars->endian);
}

int	zoom(int button, int x, int y, t_vars *vars)
{
	if (button == 4)
		vars->zoom *= 1.1;
	else if (button == 5)
		vars->zoom /= 1.1;
	vars->move.re_x = (x - WIDTH / 2) / (3 * vars->zoom * WIDTH) + vars->move.re_x;
	vars->move.im_y = (y - HEIGHT / 2) / (3 * vars->zoom * HEIGHT) + vars->move.im_y;
	fractal(vars);
	return (0);
}

int	reaload_window(t_vars *vars)
{
	mlx_clear_window(vars->mlx_ptr, vars->win_ptr);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, 0, 0);
	return (0);
}

void	init_window(uint8_t argc)
{
	t_vars	vars;

	vars.type = argc;
	init_vars(&vars);
	mlx_hook(vars.win_ptr, 4, 1L << 2, zoom, &vars);
	mlx_hook(vars.win_ptr, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win_ptr, 17, 1L << 17, close_window, &vars);
	fractal(&vars);
	mlx_loop(vars.mlx_ptr);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			init_window(0);
		else if (ft_strcmp(argv[1], "julia") == 0)
			init_window(1);
		else if (ft_strcmp(argv[1], "burningship") == 0)
			init_window(2);
		else
			ft_putstr_fd("Error\n", 1);
	}
	else
		ft_putstr_fd("\t------Error------\nUsage: ./fract_ol [fractal_name]\nAvailable fractals: mandelbrot, julia, burningship\n", 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 03:16:36 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/05 19:42:29 by cfrancie         ###   ########.fr       */
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
	vars->img = ft_calloc(vars->window_width * vars->window_height, sizeof(int));
	if (!vars->img)
	{
		perror("ft_calloc");
		exit(EXIT_FAILURE);
	}
	vars->zoom = 1;
	vars->x_screen = 0;
	vars->y_screen = 0;
	vars->re = 0;
	vars->im = 0;
	vars->old_re = 0;
	vars->old_im = 0;
}

/*
* init_fract
*/
void	init_window(char *arg)
{
	t_vars	vars;

	init_vars(&vars);
	if (ft_strcmp(arg, "mandelbrot") == 0)
		mandelbrot(&vars);
	else
	{
		printf("Error\n");
		exit(0);
	}
	put_img_tab(&vars);
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

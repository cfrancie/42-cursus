/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:56:14 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/08 18:18:38 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

/*
Close and free the window
*/
int	close_window(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->mlx_win);
	free(vars->img);
	free(vars->addr);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		free(vars->mlx);
		exit(0);
	}
	if (keycode == 65451 && vars->max_iter < 1000)
		vars->max_iter += 5;
	if (keycode == 65453 && vars->max_iter > 10)
		vars->max_iter -= 5;
	if (keycode == 65470)
	{
		vars->max_iter = 100;
		vars->zoom = 1;
		vars->move_x = 0;
		vars->move_y = 0;
	}
	fractal(vars);
	return (0);
}

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
	mlx_loop_end(vars->mlx_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_image(vars->mlx_ptr, vars->img_ptr);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		free(vars->mlx_ptr);
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
		vars->move.re_x = 0;
		vars->move.im_y = 0;
	}
	fractal(vars);
	return (0);
}

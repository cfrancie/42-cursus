/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:23:13 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/09 23:09:58 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// anti aliasing fxaa
static int	coloring(int i, int max_iter)
{
	double	t;

	t = (double)i / (double)max_iter;
	return ((int)(9 * (1 - t) * (t * t * t) * 0xFFFFFF));
}

void	chose_color(t_vars *vars, int x, int y, int i)
{
	if (i == vars->max_iter)
		my_mlx_pixel_put(vars, x, y, 0x000000);
	else
		my_mlx_pixel_put(vars, x, y, coloring(i, vars->max_iter));
}

void	fractal(t_vars *vars)
{
	vars->window_pos.y = 0;
	while (vars->window_pos.y < WIN_HEIGHT)
	{
		vars->window_pos.x = 0;
		while (vars->window_pos.x < WIN_WIDTH)
		{
			if (vars->type == 0)
				mandelbrot(vars, vars->window_pos.x, vars->window_pos.y);
			else if (vars->type == 1)
				julia(vars, vars->window_pos.x, vars->window_pos.y);
			else if (vars->type == 2)
				burningship(vars, vars->window_pos.x, vars->window_pos.y);
			++vars->window_pos.x;
		}
		++vars->window_pos.y;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, 0, 0);
}

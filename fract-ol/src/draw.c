/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:23:13 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/12 16:55:10 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

static void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	lch_coloring(int i, int max_iter)
{
	double		t;
	int			r;
	int			g;
	int			b;

	t = (double)i / (double)max_iter;
	r = 9 * (1 - t) * t * t * t * 255;
	g = 15 * (1 - t) * (1 - t) * t * t * 255;
	b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	return (r << 16 | g << 8 | b);
}

void	chose_color(t_vars *vars, int x, int y, int i)
{
	if (i == vars->max_iter)
		my_mlx_pixel_put(vars, x, y, 0x000000);
	else
		my_mlx_pixel_put(vars, x, y, lch_coloring(i, vars->max_iter));
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
			else if (vars->type == 1 || vars->type == 3)
				julia(vars, vars->window_pos.x, vars->window_pos.y);
			else if (vars->type == 2)
				burning_ship(vars, vars->window_pos.x, vars->window_pos.y);
			vars->window_pos.x++;
		}
		vars->window_pos.y++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, 0, 0);
}

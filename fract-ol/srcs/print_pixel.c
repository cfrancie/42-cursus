/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:55:43 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/06 04:27:47 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"


t_complex	square(double re, double im)
{
	t_complex	z;

	z.re = re * re - im * im;
	z.im = 2 * re * im;
	return (z);
}

/*
type = 0 -> mandelbrot
type = 1 -> julia
type = 2 -> burning_ship
*/
int	is_diverge(t_vars *vars, int max_iteration)
{
	int			i;
	t_complex	z;

	i = 0;
	z.re = 0;
	z.im = 0;
	while (i < max_iteration)
	{
		z = square(z.re, z.im);
		z.re += vars->re;
		z.im += vars->im;
		if (z.re * z.re + z.im * z.im > 4)
			return (i);
		i++;
	}
	return (i);
}

void	put_color(t_vars *vars, int x, int y, int color, int max_iteration)
{
	if (color == max_iteration)
		mlx_pixel_put(vars->mlx, vars->mlx_win, x, y, 0x000000);
	else
		mlx_pixel_put(vars->mlx, vars->mlx_win, x, y, 0x0A50FF * color % 0xFFFFFF);
}

void	fractal(t_vars *vars, int max_iteration)
{
	int		x;
	int		y;
	int		i;
	
	x = 0;
	while (x < vars->window_width)
	{
		y = 0;
		while (y < vars->window_height)
		{
			vars->re = 1.5 * (x - vars->window_width / 2) / (0.5 * vars->zoom * vars->window_width) + vars->move_x;
			vars->im = (y - vars->window_height / 2) / (0.5 * vars->zoom * vars->window_height) + vars->move_y;
			i = is_diverge(vars, max_iteration);
			put_color(vars, x, y, i, max_iteration);
			y++;
		}
		x++;
	}
}

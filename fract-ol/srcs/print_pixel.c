/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:55:43 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/05 22:36:21 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

double	power_complex(double re, double im)
{
	return (re * re - im * im);
}

int	is_diverge(t_vars *vars)
{
	double	tmp_re;
	double	tmp_im;
	int		i;
	
	i = 0;
	while (i < 100)
	{
		tmp_re = power_complex(vars->re, vars->im);
		tmp_im = 2 * vars->re * vars->im;
		vars->re = tmp_re + vars->old_re;
		vars->im = tmp_im + vars->old_im;
		if (vars->re * vars->re + vars->im * vars->im > 4)
			return (0);
		i++;
	}
	return (i);
}

void	put_color(t_vars *vars, int x, int y, int color)
{
	// displays the color as a function of time to converge and black if it converges
	if (color == 100)
		mlx_pixel_put(vars->mlx, vars->mlx_win, x, y, 0x000000);
	else
		mlx_pixel_put(vars->mlx, vars->mlx_win, x, y, 0x00FFFFFF);
}

void	mandelbrot(t_vars *vars)
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
			vars->re = 1.5 * (x - vars->window_width / 2) / (0.5 * vars->zoom * vars->window_width) + vars->x_screen;
			vars->im = (y - vars->window_height / 2) / (0.5 * vars->zoom * vars->window_height) + vars->y_screen;
			vars->old_re = vars->re;
			vars->old_im = vars->im;
			i = is_diverge(vars);
			put_color(vars, x, y, i);
			y++;
		}
		x++;
	}
}

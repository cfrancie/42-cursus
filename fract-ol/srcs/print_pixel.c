/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:55:43 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/07 20:24:26 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static double	abs_double(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	is_diverge(int max_iteration, t_complex z, int type, t_vars *vars)
{
	int			i;
	t_complex	tmp;
	t_complex	c;

	i = 0;
	c.re = 0;
	c.im = 0;
	if (type == 1)
	{
		c.re = vars->re;
		c.im = vars->im;
	}
	if (type == 0 || type == 2)
	{
		c.re = z.re;
		c.im = z.im;
	}
	while (i < max_iteration)
	{
		if (z.re * z.re + z.im * z.im > 4)
			return (i);
		if (type == 2)
		{
			z.re = abs_double(z.re);
			z.im = abs_double(z.im);
		}
		tmp.re = z.re;
		tmp.im = z.im;
		z.re = tmp.re * tmp.re - tmp.im * tmp.im + c.re;
		z.im = 2 * tmp.re * tmp.im + c.im;
		i++;
	}
	return (i);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_color(t_vars *vars, int x, int y, int color, int max_iteration)
{	
	if (color == max_iteration)
		my_mlx_pixel_put(vars, x, y, 0x000000);
	else
		my_mlx_pixel_put(vars, x, y, (0x123456 + color * 0x0F0F0F));
}

void	fractal(t_vars *vars, int max_iteration)
{
	t_complex	z;
	int			x;
	int			y;
	int			i;

	x = 0;
	while (x < vars->window_width)
	{
		y = 0;
		while (y < vars->window_height)
		{
			// determine to which position on the plane the pixel (x, y) corresponds
			z.re = 1.5 * (x - vars->window_width / 2) / (0.5 * vars->zoom * vars->window_width) + vars->move_x;
			z.im = (y - vars->window_height / 2) / (0.5 * vars->zoom * vars->window_height) + vars->move_y;
			i = is_diverge(max_iteration, z, vars->type, vars);
			put_color(vars, x, y, i, max_iteration);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
}

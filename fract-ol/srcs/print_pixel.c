/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:55:43 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/08 17:51:41 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

t_complex	ini_comp(t_vars *vars, t_complex z)
{
	t_complex	c;

	c.re = 0;
	c.im = 0;
	if (vars->type == 1)
	{
		c.re = vars->re;
		c.im = vars->im;
	}
	if (vars->type == 0 || vars->type == 2)
	{
		c.re = z.re;
		c.im = z.im;
	}
	return (c);
}

int	is_diverge(int max_iteration, t_complex z, int type, t_vars *vars)
{
	int			i;
	t_complex	tmp;
	t_complex	c;

	c = ini_comp(vars, z);
	i = 0;
	while (i < max_iteration)
	{
		if (z.re * z.re + z.im * z.im > 4.)
			return (i);
		if (type == 2)
		{
			z.re = z.re;
			if (z.re < 0.)
				z.re = -z.re;
			z.im = z.im;
			if (z.im < 0.)
				z.im = -z.im;
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

void	put_color(t_vars *vars, int x, int y, t_complex z)
{	
	int	color;

	color = is_diverge(vars->max_iter, z, vars->type, vars);
	if (color == vars->max_iter)
		my_mlx_pixel_put(vars, x, y, 0x000000);
	else
		my_mlx_pixel_put(vars, x, y, (0x123456 + color * 0x0F0F0F));
}

void	fractal(t_vars *vars)
{
	t_complex	z;
	int			x;
	int			y;

	x = 0;
	while (x < vars->window_width)
	{
		y = 0;
		while (y < vars->window_height)
		{
			z.re = 1.5 * (x - vars->window_width / 2)
				/ (0.5 * vars->zoom * vars->window_width) + vars->move_x;
			z.im = (y - vars->window_height / 2)
				/ (0.5 * vars->zoom * vars->window_height) + vars->move_y;
			put_color(vars, x, y, z);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:55:43 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/08 22:14:58 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

t_complex	init_comp(t_vars *vars, t_complex z)
{
	t_complex	c;

	c.re_x = 0;
	c.im_y = 0;
	if (vars->type == 1)
	{
		c.re_x = vars->comp.re_x;
		c.im_y = vars->comp.im_y;
	}
	if (vars->type == 0 || vars->type == 2)
	{
		c.re_x = z.re_x;
		c.im_y = z.im_y;
	}
	return (c);
}

int	is_diverge(int max_iteration, t_complex z, int type, t_vars *vars)
{
	int			i;
	t_complex	tmp;
	t_complex	c;

	c = init_comp(vars, z);
	i = 0;
	while (i < max_iteration)
	{
		if (z.re_x * z.re_x + z.im_y * z.im_y > 4.)
			return (i);
		if (type == 2)
		{
			if (z.re_x < 0.)
				z.re_x = -z.re_x;
			if (z.im_y < 0.)
				z.im_y = -z.im_y;
		}
		tmp.re_x = z.re_x;
		tmp.im_y = z.im_y;
		z.re_x = tmp.re_x * tmp.re_x - tmp.im_y * tmp.im_y + c.re_x;
		z.im_y = 2 * tmp.re_x * tmp.im_y + c.im_y;
		i++;
	}
	return (i);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr_ptr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_color(t_vars *vars, int x, int y, t_complex z)
{
	int	color;

	color = is_diverge(vars->max_iter, z, vars->type, vars);
	if (color == vars->max_iter)
		my_mlx_pixel_put(vars, x, y, 0x000000);
	else
		my_mlx_pixel_put(vars, x, y, (0x654321 + (color * ((vars->move.im_y + 1)/ (vars->move.re_x + 1))* 0x0F0F0F)));
}

void	fractal(t_vars *vars)
{
	t_complex	z;
	t_coords 	coords;

	coords.x = 0;
	while (coords.x < WIDTH)
	{
		coords.y = 0;
		while (coords.y < HEIGHT)
		{
			z.re_x = (coords.x - WIDTH / 2) / (0.5 * vars->zoom * WIDTH) + vars->move.re_x;
			z.im_y = (coords.y - HEIGHT / 2) / (0.5 * vars->zoom * HEIGHT) + vars->move.im_y;
			put_color(vars, coords.x, coords.y, z);
			coords.y++;
		}
		coords.x++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, 0, 0);
}

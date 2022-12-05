/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:55:43 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/05 19:42:09 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	is_diverge(double res)
{
	return (res > 100);
}

void	mandelbrot(t_vars *vars)
{
	int		x;
	int		y;
	double	res;

	y = 0;
	while (y < vars->window_height)
	{
		x = 0;
		while (x < vars->window_width)
		{
			vars->re = 1.5 * (x - vars->window_width / 2) / (0.5 * vars->zoom * vars->window_width) + vars->x_screen;
			vars->im = (y - vars->window_height / 2) / (0.5 * vars->zoom * vars->window_height) + vars->y_screen;
			vars->old_re = vars->re;
			vars->old_im = vars->im;
			res = 0;
			while (res < 100 && (vars->re * vars->re + vars->im * vars->im) < 4)
			{
				vars->old_re = vars->re;
				vars->old_im = vars->im;
				vars->re = vars->old_re * vars->old_re - vars->old_im * vars->old_im + vars->x_screen;
				vars->im = 2 * vars->old_re * vars->old_im + vars->y_screen;
				res++;
			}
			if (is_diverge(res))
				vars->img[y * vars->window_width + x] = 0x000000;
			else
				vars->img[y * vars->window_width + x] = 0xFFFFFF;
			x++;
		}
		y++;
	}
}

void	put_img_tab(t_vars *vars)
{
	int		i;
	int		tmp_x;
	int		tmp_y;

	i = 0;
	tmp_x = 0;
	tmp_y = 0;
	while (i < (vars->window_height * vars->window_width))
	{
		mlx_pixel_put(vars->mlx, vars->mlx_win, tmp_x, tmp_y, vars->img[i]);
		tmp_x++;
		if (tmp_x == 800)
		{
			tmp_x = 0;
			tmp_y++;
		}
		i++;
	}
}

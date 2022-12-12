/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:25:44 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/12 16:34:06 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

void	mandelbrot(t_vars *vars, int x, int y)
{
	t_complex	z;
	t_complex	o;
	double		tmp;
	int			i;

	o.re = 0;
	o.im = 0;
	z.re = (x - WIN_WIDTH / 2)
		/ (0.5 * vars->zoom * WIN_WIDTH) + vars->move.re;
	z.im = (y - WIN_HEIGHT / 2)
		/ (0.5 * vars->zoom * WIN_HEIGHT) + vars->move.im;
	i = 0;
	while (o.re * o.re + o.im * o.im <= 4 && i < vars->max_iter)
	{
		tmp = o.re * o.re - o.im * o.im + z.re;
		o.im = 2 * o.re * o.im + z.im;
		o.re = tmp;
		i++;
	}
	chose_color(vars, x, y, i);
}

void	julia(t_vars *vars, int x, int y)
{
	t_complex	z;
	double		tmp;
	int			i;

	z.re = (x - WIN_WIDTH / 2)
		/ (0.5 * vars->zoom * WIN_WIDTH) + vars->move.re;
	z.im = (y - WIN_HEIGHT / 2)
		/ (0.5 * vars->zoom * WIN_HEIGHT) + vars->move.im;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < vars->max_iter)
	{
		tmp = z.re * z.re - z.im * z.im + vars->c.re;
		z.im = 2 * z.re * z.im + vars->c.im;
		z.re = tmp;
		i++;
	}
	chose_color(vars, x, y, i);
}

void	burning_ship(t_vars *vars, int x, int y)
{
	t_complex	z;
	t_complex	o;
	double		tmp;
	int			i;

	o.re = 0;
	o.im = 0;
	z.re = (x - WIN_WIDTH / 2)
		/ (0.5 * vars->zoom * WIN_WIDTH) + vars->move.re;
	z.im = (y - WIN_HEIGHT / 2)
		/ (0.5 * vars->zoom * WIN_HEIGHT) + vars->move.im;
	i = 0;
	while (o.re * o.re + o.im * o.im <= 4 && i < vars->max_iter)
	{
		tmp = o.re * o.re - o.im * o.im + z.re;
		o.im = 2 * fabs(o.re * o.im) + z.im;
		o.re = tmp;
		i++;
	}
	chose_color(vars, x, y, i);
}

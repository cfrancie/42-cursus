/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   draw.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cfrancie <cfrancie@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/06 22:09:32 by cfrancie		  #+#	#+#			 */
/*   Updated: 2022/12/11 00:53:44 by cfrancie		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */


#include "../inc/main.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	LCH_Coloring(int i, int max_iter)
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
		my_mlx_pixel_put(vars, x, y, LCH_Coloring(i, vars->max_iter));
}


void mandelbrot(t_vars *vars, int x, int y)
{
	t_complex	z;
	t_complex	o;
	double		tmp;
	int			i;

	o.re = 0;
	o.im = 0;
	z.re = (x - WIN_WIDTH / 2) / (0.5 * vars->zoom * WIN_WIDTH) + vars->move.re;
	z.im = (y - WIN_HEIGHT / 2) / (0.5 * vars->zoom * WIN_HEIGHT) + vars->move.im;
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

	z.re = (x - WIN_WIDTH / 2) / (0.5 * vars->zoom * WIN_WIDTH) + vars->move.re;
	z.im = (y - WIN_HEIGHT / 2) / (0.5 * vars->zoom * WIN_HEIGHT) + vars->move.im;
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
	z.re = (x - WIN_WIDTH / 2) / (0.5 * vars->zoom * WIN_WIDTH) + vars->move.re;
	z.im = (y - WIN_HEIGHT / 2) / (0.5 * vars->zoom * WIN_HEIGHT) + vars->move.im;
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

void fractal(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (vars->type == 0)
				mandelbrot(vars, x, y);
			else if (vars->type == 1 || vars->type == 3)
				julia(vars, x, y);
			else if (vars->type == 2)
				burning_ship(vars, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->img_ptr, 0, 0);
}
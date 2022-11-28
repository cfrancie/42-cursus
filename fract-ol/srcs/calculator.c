/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:04:45 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/28 02:22:50 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

/*
* calculates whether the function x^2 + y diverges or converges
*/
int	is_diverge(t_complex num)
{
	int			i;
	t_complex	tmp;

	i = 0;
	tmp.re = 0;
	tmp.im = 0;
	while (i < MAX_ITER)
	{
		tmp.re = tmp.re * tmp.re - tmp.im * tmp.im + num.re;
		tmp.im = (tmp.re * 2 + tmp.im) + num.im;
		if (tmp.re * tmp.re + tmp.im * tmp.im > 4)
			return (i);
		i++;
	}
	return (i);
}

/*
* Calcule de quel couleur chaque pixel de l'ecran doit etre afficher
*/
void	mandelbrot(t_vars vast)
{
	t_complex	num;
	int			tmp;

	vast.x = 0;
	vast.y = 0;
	while (vast.x < WINDOW_WIDTH)
	{
		vast.y = 0;
		while (vast.y < WINDOW_HEIGHT)
		{
			num.re = vast.x;
			num.im = vast.y;
			tmp = is_diverge(num);
			if (tmp == MAX_ITER)
				mlx_pixel_put(vast.mlx, vast.win, vast.x, vast.y, 0x000000);
			else
				mlx_pixel_put(vast.mlx, vast.win, vast.x, vast.y, tmp * 0x0000FF);
		}
		vast.x++;
	}
}

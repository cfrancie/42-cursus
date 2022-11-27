/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:04:45 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/27 19:45:37 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

static double	mandelbrot_equa(t_complex tmp)
{
	return (tmp.re * 2 + tmp.im);
}

/*
* Renvoie -1 si la suite ne diverge pas et le nombre
* d'iteration de la suite si elle l'es
*/
int	is_diverge(t_complex num, double (*f)(t_complex), int max_iteration)
{
	t_complex	tmp;
	int			i;

	i = 0;
	tmp.re = f(num);
	while (i < max_iteration)
	{
		tmp.re = f(tmp);
		i++;
	}
	if (tmp.re >= 100 || tmp.re <= 100)
		return (i);
	return (-1);
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
			tmp = is_diverge(num, mandelbrot_equa, 100);
			if (tmp == -1)
				set_color(vast, 0);
			else
				set_color(vast, 1);
			vast.y++;
		}
		vast.x++;
	}
}

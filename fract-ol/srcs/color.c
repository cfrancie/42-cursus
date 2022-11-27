/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 02:23:32 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/27 19:42:11 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	set_color(t_vars vars, int div)
{
	if (div)
		mlx_pixel_put(vars.mlx, vars.win, vars.x, vars.y, 0x0033FF);
	else
		mlx_pixel_put(vars.mlx, vars.win, vars.x, vars.y, 0xFF33FF);
}

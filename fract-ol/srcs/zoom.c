/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:44:35 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/29 20:46:43 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void    zoom(t_fractol *fractol, double value)
{
    fractol->zoom *= value;
    fractol->x1 *= value;
    fractol->x2 *= value;
    fractol->y1 *= value;
    fractol->y2 *= value;
}
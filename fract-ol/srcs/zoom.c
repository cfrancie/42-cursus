/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:17:21 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/28 02:20:21 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void    zoom(t_vars *vast, int x, int y, double zoom)
{
    t_complex   num;
    int         tmp;

    vast->x = 0;
    vast->y = 0;
    while (vast->x < WINDOW_WIDTH)
    {
        vast->y = 0;
        while (vast->y < WINDOW_HEIGHT)
        {
            num.re = (vast->x - WINDOW_WIDTH / 2) / (0.5 * zoom * WINDOW_WIDTH) + x;
            num.im = (vast->y - WINDOW_HEIGHT / 2) / (0.5 * zoom * WINDOW_HEIGHT) + y;
            tmp = is_diverge(num);
            set_color(*vast, tmp);
            vast->y++;
        }
        vast->x++;
    }
    mlx_put_image_to_window(vast->mlx, vast->win, vast->img, 0, 0);
}

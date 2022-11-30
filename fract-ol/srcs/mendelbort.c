/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:48:51 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/30 19:29:30 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void    mendelbort(t_fractol fract)
{
    int     x;
    int     y;
    double  c_r;
    double  c_i;
    double  z_r;
    double  z_i;
    double  tmp;
    int     i;

    x = 0;
    while (x < WINDOW_WIDTH)
    {
        y = 0;
        while (y < WINDOW_HEIGHT)
        {
            c_r = x / fract.zoom + fract.x1;
            c_i = y / fract.zoom + fract.y1;
            z_r = 0;
            z_i = 0;
            i = 0;
            while (z_r * z_r + z_i * z_i < 4 && i < 50)
            {
                tmp = z_r;
                z_r = z_r * z_r - z_i * z_i + c_r;
                z_i = 2 * z_i * tmp + c_i;
                i++;
            }
            if (i == 50)
                fract.data[y * WINDOW_WIDTH + x] = 0x000000;
            else
                fract.data[y * WINDOW_WIDTH + x] = 0xFFFFFF;
            y++;
        }
        x++;
    }
}

void    julia(t_fractol fract)
{
    int     x;
    int     y;
    double  c_r;
    double  c_i;
    double  z_r;
    double  z_i;
    double  tmp;
    int     i;

    x = 0;
    while (x < WINDOW_WIDTH)
    {
        y = 0;
        while (y < WINDOW_HEIGHT)
        {
            c_r = x / fract.zoom + fract.x1;
            c_i = y / fract.zoom + fract.y1;
            z_r = 0;
            z_i = 0;
            i = 0;
            while (z_r * z_r + z_i * z_i < 4 && i < 50)
            {
                tmp = z_r;
                z_r = z_r * z_r - z_i * z_i + c_r;
                z_i = 2 * z_i * tmp + c_i;
                i++;
            }
            if (i == 50)
                fract.data[y * WINDOW_WIDTH + x] = 0x000000;
            else
                fract.data[y * WINDOW_WIDTH + x] = 0xFFFFFF;
            y++;
        }
        x++;
    }
}
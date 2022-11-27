/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 03:16:36 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/27 03:17:30 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int main(int argc, char  **arg)
{
    t_fractol	*fractol;

    if (argc != 2)
    {
        printf("Usage: ./fractol [fractal name]\n");
        return (0);
    }
    if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
        return (0);
    if (!(fractol->mlx = mlx_init()))
        return (0);
    if (!(fractol->win = mlx_new_window(fractol->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fractol")))
        return (0);
    mlx_loop(fractol->mlx);  
    return 0;
}
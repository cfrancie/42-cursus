/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:16:56 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/11 03:44:55 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

int     key_hook(int keycode, t_vars *vars)
{
    // if it is the directional keys then we go to we move to the direction indicated
    if (keycode == 65362)
        vars->move.im -= 0.1 / vars->zoom;
    else if (keycode == 65364)
        vars->move.im += 0.1 / vars->zoom;
    else if (keycode == 65361)
        vars->move.re -= 0.1 / vars->zoom;
    else if (keycode == 65363)
        vars->move.re += 0.1 / vars->zoom;
    
    // close and clear the program if the escape key is pressed
    else if (keycode == 65307)
    {
        mlx_loop_end(vars->mlx_ptr);
        mlx_destroy_display(vars->mlx_ptr);
        free(vars->mlx_ptr);
        exit(0);
    }
    // if f1 is pressed reset the zoom and the move
    else if (keycode == 65470)
    {
        vars->zoom = 1;
        vars->move.re = 0;
        vars->move.im = 0;
        vars->max_iter = 50;
    }
    fractal(vars);
	put_text(vars);
    return (0);
}

int mouse_hook(int button, int x, int y, t_vars *vars)
{
 	if (button == 4 || button == 5)
    {
        if (button == 4)
		    vars->zoom *= 1.1;
        else if (button == 5 && vars->zoom > 0.02)
            vars->zoom /= 1.1;
    	vars->move.re = (x - WIN_WIDTH / 2)
		    / (3 * vars->zoom * WIN_WIDTH) + vars->move.re;
	    vars->move.im = (y - WIN_HEIGHT / 2)
		    / (3 * vars->zoom * WIN_HEIGHT) + vars->move.im;
    }
	fractal(vars);
    put_text(vars);
    return (0);
}

int close_window(t_vars *vars)
{
    mlx_loop_end(vars->mlx_ptr);
    mlx_destroy_display(vars->mlx_ptr);
    free(vars->mlx_ptr);
    exit(0);
}
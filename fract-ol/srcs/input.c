/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:56:14 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/07 01:01:23 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

/*
Close and free the window
*/
int	close_window(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	return (0);
}

/*
zoom in and out with the mouse wheel
*/

int input_vars(t_vars *vars)
{
	mlx_hook(vars->mlx_win, 17, 1L << 17, close_window, &vars);
    return (0);
}

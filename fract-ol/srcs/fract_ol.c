/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 03:16:36 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/04 07:59:54 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

/*
Initialise les valeurs de la structure t_vars mise en paramettre
return: [void]
parm: t_vars [poitier sur vars]
*/
void	init_vars(t_vars *vars)
{
	vars->x_screen = 0;
	vars->y_screen = 0;
	vars->x_fract = 0;
	vars->y_fract = 0;
	vars->zoom_value = 0;
	vars->mlx = mlx_init();
	vars->window_height = 1280;
	vars->window_width = 720;
}

/*
Creer la fenetre de jeu avec comme nom de fenettre
la chaine de caractere mise en paramettre
return: [void]
param: char [chaime de caractere]
*/
void	init_window(char *arg)
{
	t_vars	*vars;

	vars = NULL;
	init_vars(vars);
	printf("%i\n", vars->x_screen);
	vars->mlx_win = mlx_new_window(vars->mlx, vars->window_height,
			vars->window_width, arg);
	mlx_loop(vars->mlx_win);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || (ft_strncmp(argv[1], "Julia", 6) != 0
			&& ft_strncmp(argv[1], "Mandelbrot", 11) != 0))
	{
		write(1, "[Julia, Mandelbrot]", 20);
		return (1);
	}
	init_window(argv[1]);
	return (0);
}

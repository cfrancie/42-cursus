/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:41:13 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/05 19:41:44 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

// write, close, read
# include <unistd.h>
// open,
# include <fcntl.h>
// malloc, free, exit
# include <stdlib.h>
// perror 
# include <stdio.h> 
// strerror
# include <string.h>

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	int		window_width;
	int		window_height;
	int		*img;
	double	zoom;
	int		x_screen;
	int		y_screen;
	double	re;
	double	im;
	double	old_re;
	double	old_im;
}	t_vars;

// fract_ol.c
void	init_vars(t_vars *vars);
void	init_window(char *arg);

// print_pixel.c
int		is_diverge(double res);
void	mandelbrot(t_vars *vars);
void	put_img_tab(t_vars *vars);

// utilities.c


#endif
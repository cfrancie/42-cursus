/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:41:13 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/06 04:25:25 by cfrancie         ###   ########.fr       */
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

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	int		window_width;
	int		window_height;
	double	zoom;
	int		x_screen;
	int		y_screen;
	double	re;
	double	im;
	double	move_x;
	double	move_y;
	int		max_iter;
}	t_vars;


// fract_ol.c
void		init_vars(t_vars *vars);
void		init_window(char *arg);

// print_pixel.c
void		fractal(t_vars *vars, int max_iteration);
void		put_color(t_vars *vars, int x, int y, int color, int max_iteration);
int			is_diverge(t_vars *vars, int max_iteration);
t_complex	square(double re, double im);


#endif
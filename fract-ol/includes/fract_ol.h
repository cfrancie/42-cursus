/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:41:13 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/08 18:15:31 by cfrancie         ###   ########.fr       */
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
	void		*mlx;
	void		*mlx_win;
	int			window_width;
	int			window_height;
	int			x_screen;
	int			y_screen;
	double		zoom;
	double		re;
	double		im;
	double		move_x;
	double		move_y;
	int			max_iter;
	int			type;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_vars;

// fract_ol.c
void		init_vars(t_vars *vars);
void		init_window(char **argv, int argc);
int			zoom(int button, int x, int y, t_vars *vars);

// print_pixel.c
t_complex	init_comp(t_vars *vars, t_complex z);
int			is_diverge(int max_iteration, t_complex z, int type, t_vars *vars);
void		my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void		put_color(t_vars *vars, int x, int y, t_complex z);
void		fractal(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);

// keyboard.c
int			close_window(t_vars *vars);

#endif
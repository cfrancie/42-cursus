/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:55:15 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/11 03:44:41 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

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
// log
# include <math.h>

// include libs
# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/minilibx-linux/mlx_int.h"

// define
# define WIN_WIDTH 800
# define WIN_HEIGHT 800

typedef struct s_complex
{
	double		re;
	double		im;
}   t_complex;

typedef struct s_screen
{
	int			x;
	int			y;
}   t_screen;

typedef struct s_vars
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	uint8_t		type;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		zoom;
	int			max_iter;
	t_screen	window_pos;
	t_complex	c;
	t_complex	move;
}   t_vars;

// prototypes
// main.c
void	init_vars(t_vars *vars);
void	put_text(t_vars *vars);

// draw.c
void	fractal(t_vars *vars);
void	mandelbrot(t_vars *vars, int x, int y);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

// input.c
int		close_window(t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int     key_hook(int keycode, t_vars *vars);


#endif
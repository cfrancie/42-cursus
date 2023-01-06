/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:55:15 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/06 18:22:48 by cfrancie         ###   ########.fr       */
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

# include <stdint.h>

// include libs
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/minilibx-linux/mlx_int.h"
# include "../../libft/libft.h"

// define
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

typedef struct s_complex
{
	long double		re;
	long double		im;
}	t_complex;

typedef struct s_screen
{
	int			x;
	int			y;
}	t_screen;

typedef struct s_vars
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	int				type;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	long double		zoom;
	int				max_iter;
	t_screen		window_pos;
	t_complex		c;
	t_complex		move;
}	t_vars;

// prototypes
// main.c
void	init_vars(t_vars *vars);

// draw.c
void	chose_color(t_vars *vars, int x, int y, int i);
void	fractal(t_vars *vars);

// input.c
int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		close_window(t_vars *vars);

// generate.c
void	mandelbrot(t_vars *vars, int x, int y);
void	julia(t_vars *vars, int x, int y);
void	burning_ship(t_vars *vars, int x, int y);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:41:13 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/27 19:36:40 by cfrancie         ###   ########.fr       */
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

# include "../srcs/minilibx-linux/mlx.h"
# include "../srcs/libft/libft.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}	t_vars;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

void	set_color(t_vars vars, int div);
int		is_diverge(t_complex num, double (*f)(t_complex), int max_iteration);
void	mandelbrot(t_vars vast);

#endif
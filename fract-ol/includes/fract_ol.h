/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:41:13 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/04 07:36:28 by cfrancie         ###   ########.fr       */
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

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300

typedef struct s_vars
{
	int		x_screen;
	int		y_screen;
	double	x_fract;
	double	y_fract;
	double	zoom_value;
	void	*mlx;
	void	*mlx_win;
	int		window_width;
	int		window_height;
}	t_vars;


// fract_ol.c
void	init_vars(t_vars *vars);
void	init_window(char *arg);

#endif
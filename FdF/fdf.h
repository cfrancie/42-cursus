/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:41:08 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/25 17:21:47 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// strerror
# include <string.h>
// perror
# include <stdio.h> 
// open, close, read
# include <fcntl.h>
// exit, malloc
# include <stdlib.h>
// write
# include <unistd.h>
// DES MAHS OEEEEEEE
# include <math.h>

# include "./minilibx-linux/mlx.h"

typedef struct s_fdf
{
	int	x;
	int	y;
	int	z;
}	t_fdf;



#endif
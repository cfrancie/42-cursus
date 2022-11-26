/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:36:03 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/26 20:14:31 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

int	init_windows(char *title)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	(void)title;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx_pixel_put(mlx, mlx_win, 5, 5, 0xFF0033);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Julia\nMandelbrot\n", 18);
		return (1);
	}
	init_windows(argv[1]);
	return (0);
}

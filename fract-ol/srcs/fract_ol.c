/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 03:16:36 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/30 19:33:18 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_ol.h"

void	ft_init_window(t_fractol *fractol, char **argv)
{
	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, argv[1]);
	fractol->img = mlx_new_image(fractol->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	fractol->data = (int *)mlx_get_data_addr(fractol->img,
			&fractol->bpp, &fractol->size_line, &fractol->endian);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	if (ft_strncmp(argv[1], "Mendelbrot", 11) == 0)
		mendelbort(*fractol);
	else if (ft_strncmp(argv[1], "Julia", 6) == 0)
		julia(*fractol);
	mlx_loop(fractol->mlx);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fractol [fractal name]", 1);
		return (0);
	}
	fractol = NULL;
	if (ft_strncmp(argv[1], "Mendelbrot", 11) == 0)
		ft_init_window(fractol, argv);
	else if (ft_strncmp(argv[1], "Julia", 6) == 0)
		ft_init_window(fractol, argv);
	else
		ft_putstr_fd("usage: ./fractol [fractal name]", 1);
	return (0);
}

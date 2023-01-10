/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:26:10 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/10 05:22:42 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int			atoi_index(char *str, int i)
{
	char	*new;

	new = str + i;
	return (ft_atoi(new));
}

long double	atof_index(char *str, int i)
{
	char	*new;

	new = str + i;
	return (ft_atof(new));
}

int	type_init(int argc, char **argv)
{
	if (argc >= 2 && !ft_strcmp(argv[1], "mandelbrot"))
		return (0);
	if (argc >= 2 && !ft_strcmp(argv[1], "julia"))
		return (1);
	if (argc >= 2 && !ft_strcmp(argv[1], "burningship"))
		return (2);
	return (-1);
}

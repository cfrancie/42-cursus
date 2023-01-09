/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:26:10 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/09 20:57:02 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

bool	check_num(int index, char **argv, bool is_float)
{
	size_t	i;

	i = 0;
	while (argv[index][i])
	{
		if (is_float)
		{
			
		}
	}
}

bool	verify_arg(int argc, char **argv)
{
	if (argc < 3 || argc > 5)
		return (print_param());
	while (argv[])
}

bool	set_julia(int argc, char **argv, t_vars *vars)
{
	bool	edit;

	edit = false;
	if (argc == 2 || argc == 3)
		edit = init(vars, (t_complex){0.0, 0.0}, 1);
	if (argc == 3 && edit && ft_atoi(argv[2]))
		vars->max_iter = ft_atoi(argv[2]);
	else if ((argc == 4 || argc == 5) && ft_search_char(argv[2], '.') && \
		ft_search_char(argv[3], '.'))
		edit = init(vars, (t_complex){ft_atof(argv[2]), \
			ft_atof(argv[3])}, 1);
	if (argc == 5 && ft_atoi(argv[4]) && edit)
		vars->max_iter = ft_atoi(argv[4]);
	return (edit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adl <adl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:44:02 by adl               #+#    #+#             */
/*   Updated: 2022/12/25 19:37:10 by adl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	read_argv(char **argv, t_data *pile)
{
	size_t	i;

	i = 1;
	pile->size = 0;
	while (argv[i])
	{
		pile->a = ft_lstlast(pile->a);
		pile->a->next = ft_lstnew(ft_atoi(argv[i]));
		pile->a = pile->a->next;
		pile->size++;
		i++;
	}
}

int main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 1)
	{
		read_argv(argv, data);
		if (!check_double(data) || !data->a || !data->b)
		{
			exit_andfree(data);
			ft_putstr("Error\n");
			return (0);
		}
		sort(data);
        exit_andfree(data);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
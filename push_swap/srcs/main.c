/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:44:02 by adl               #+#    #+#             */
/*   Updated: 2023/01/10 03:10:05 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	ft_putstr(const char *str)
{
	write(1, str, ft_strlen(str));
}

void	radix_sort(t_data *data)
{
	int		i;
	int		max;
	int		*count;

	i = 0;
	max = ft_lstmax(data->a);
	count = ft_calloc(max + 1, sizeof(int));
	while (i <= max)
	{
		count[i] = ft_lstcount(data->a, i);
		i++;
	}
	i = 0;
	while (i <= max)
	{
		while (count[i] > 0)
		{
			ft_pb(data);
			if (data->b->data == i)
				ft_rb(data, false);
			count[i]--;
		}
		i++;
	}
	free(count);
}

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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	data.a = ft_lstnew(0);
	data.b = ft_lstnew(0);
	read_argv(argv, &data);
	radix_sort(&data);
	ft_lstclear(&data.a);
	ft_lstclear(&data.b);
	return (0);
}

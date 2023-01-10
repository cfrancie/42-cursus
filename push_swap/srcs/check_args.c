/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:11:02 by adl               #+#    #+#             */
/*   Updated: 2023/01/10 02:46:52 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	put_swap_two(int i, t_data *data)
{
	if (i == 5)
		ft_ra(data, true);
	else if (i == 6)
		ft_rb(data, true);
	else if (i == 7)
		ft_rr(data);
	else if (i == 8)
		ft_rra(data, true);
	else if (i == 9)
		ft_rrb(data, true);
	else if (i == 10)
		ft_rrr(data);
	else
		ft_putstr("Error\n");
}

void	put_swap_one(int i, t_data *data)
{
	if (i == 0)
		ft_sa(data, true);
	else if (i == 1)
		ft_sb(data, true);
	else if (i == 2)
		ft_ss(data);
	else if (i == 3)
		ft_pa(data);
	else if (i == 4)
		ft_pb(data);
	else
		put_swap_two(i, data);
}

bool	check_double(t_data *data)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = data->a;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->data == tmp2->data)
				return (false);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (true);
}

void	free_data(t_data *data)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = data->a;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	tmp = data->b;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adl <adl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:11:02 by adl               #+#    #+#             */
/*   Updated: 2022/12/25 19:28:39 by adl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void	put_swap_two(int i, t_data *data)
{
	switch (i)
	{
	case 5:
		ft_ra(data);
		break;
	case 6:
		ft_rb(data);
		break;
	case 7:
		ft_rr(data);
		break;
	case 8:
		ft_rra(data);
		break;
	case 9:
		ft_rrb(data);
		break;
	case 10:
		ft_rrr(data);
		break;
	default:
		ft_putstr("Error");
	}
}

void	put_swap_one(int i, t_data *data)
{
	switch (i)
	{
	case 0:
        ft_sa(data);
		break;
	case 1:
		ft_sb(data);
		break;
	case 2:
        ft_ss(data);
		break;
	case 3:
        ft_pa(data);
		break;
	case 4:
        ft_pb(data);
		break;
	default:
		put_swap_two(i, data);
	}
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

void	exit_andfree(t_data *data)
{
	while (data->a->next)
	{
		free(data->a->data);
		data->a = data->a->next;
	}
	while (data->b->next)
	{
		free(data->b->data);
		data->b = data->b->next;
	}
	free(data->a);
	free(data->b);
	free(data);
	exit(0);
}

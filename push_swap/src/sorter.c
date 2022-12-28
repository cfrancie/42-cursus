/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adl <adl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:33:59 by adl               #+#    #+#             */
/*   Updated: 2022/12/27 16:58:45 by adl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int	good_order(t_data *data)
{
	t_pile	*tmp;

	tmp = data->a;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort(t_data *data)
{
	int	i;

	i = 0;
	while (!good_order(data))
	{
		if (data->a->data > data->a->next->data)
			ft_sa(data, true);
		else
			ft_ra(data, true);
		i++;
	}
	while (i--)
		ft_rra(data, true);
}

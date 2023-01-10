/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:52:42 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/10 03:01:15 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	ft_lstmax(t_pile *lst)
{
	int	max;

	max = lst->data;
	while (lst)
	{
		if (lst->data > max)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}

int	ft_lstcount(t_pile *lst, int i)
{
	int	count;

	count = 0;
	while (lst)
	{
		if (lst->data == i)
			count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_lstclear(t_pile **lst)
{
	t_pile	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

void	exit_andfree(t_data *data)
{
	ft_lstclear(&data->a);
	ft_lstclear(&data->b);
	free(data);
	exit(0);
}

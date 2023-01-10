/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:39:10 by adl               #+#    #+#             */
/*   Updated: 2023/01/10 02:05:37 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

/*Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.*/
void	ft_ra(t_data *data, bool print)
{
	t_pile	*tmp;
	t_pile	*last;

	if (data->a && data->a->next)
	{
		tmp = data->a;
		last = ft_lstlast(data->a);
		data->a = data->a->next;
		last->next = tmp;
		tmp->next = NULL;
		if (print)
			ft_putstr("ra\n");
	}
}

/*Décale d’une position vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.*/
void	ft_rb(t_data *data, bool print)
{
	t_pile	*tmp;
	t_pile	*last;

	if (data->b && data->b->next)
	{
		tmp = data->b;
		last = ft_lstlast(data->b);
		data->b = data->b->next;
		last->next = tmp;
		tmp->next = NULL;
		if (print)
			ft_putstr("rb\n");
	}
}

/*ra et rb en même temps.*/
void	ft_rr(t_data *data)
{
	ft_ra(data, 0);
	ft_rb(data, 0);
	ft_putstr("rr\n");
}

/*Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.*/
void	ft_rra(t_data *data, bool print)
{
	t_pile	*tmp;
	t_pile	*last;

	if (data->a && data->a->next)
	{
		tmp = data->a;
		last = ft_lstlast(data->a);
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = data->a;
		data->a = last;
		if (print)
			ft_putstr("rra\n");
	}
}

/*Décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.*/
void	ft_rrb(t_data *data, bool print)
{
	t_pile	*tmp;
	t_pile	*last;

	if (data->b && data->b->next)
	{
		tmp = data->b;
		last = ft_lstlast(data->b);
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = data->b;
		data->b = last;
		if (print)
			ft_putstr("rrb\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adl <adl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:00:50 by adl               #+#    #+#             */
/*   Updated: 2022/12/25 21:59:16 by adl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

/*Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun*/
void	ft_sa(t_data *data, bool print)
{
	int	tmp;

	if (data->a && data->a->next)
	{
		tmp = data->a->data;
		data->a->data = data->a->next->data;
		data->a->next->data = tmp;
		if (print)
			ft_putstr("sa\n");
	}
}

/*Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.*/
void	ft_sb(t_data *data, bool print)
{
	int	tmp;

	if (data->b && data->b->next)
	{
		tmp = data->b->data;
		data->b->data = data->b->next->data;
		data->b->next->data = tmp;
		if (print)
			ft_putstr("sb\n");
	}
}

/*sa et sb en même temps.*/
void	ft_ss(t_data *data)
{
	ft_sa(data, 0);
	ft_sb(data, 0);
	ft_putstr("ss\n");
}

/*Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.*/
void	ft_pa(t_data *data)
{
	data->a = ft_lstnew(data->b->data);
	data->b = data->b->next;
	ft_putstr("pa\n");
}

/*Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.*/
void	ft_pb(t_data *data)
{
	data->b = ft_lstnew(data->a->data);
	data->a = data->a->next;
	ft_putstr("pb\n");
}

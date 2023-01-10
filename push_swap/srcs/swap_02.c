/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:02:07 by adl               #+#    #+#             */
/*   Updated: 2023/01/10 02:49:09 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

/*rra et rrb en même temps*/
void	ft_rrr(t_data *data)
{
	ft_rra(data, false);
	ft_rrb(data, false);
	ft_putstr("rrr\n");
}

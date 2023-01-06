/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adl <adl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:02:07 by adl               #+#    #+#             */
/*   Updated: 2022/12/23 23:18:38 by adl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

/*rra et rrb en même temps*/
void	ft_rrr(t_pile *pile)
{
	ft_rra(pile, 0);
	ft_rrb(pile, 0);
	ft_putstr("rrr\n");
}
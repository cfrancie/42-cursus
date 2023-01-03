/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie@student.42.fr <cfrancie>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 02:04:19 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/02 20:52:23 by cfrancie@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_atof(const char *str)
{
	double	nb;
	double	nb2;
	int		i;
	int		j;

	nb = 0;
	nb2 = 0;
	i = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		j = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb2 = nb2 * 10 + str[i++] - '0';
	while (nb2 >= 1)
		nb2 /= 10;
	if (j == 1)
		return ((nb + nb2) * -1);
	return (nb + nb2);
}

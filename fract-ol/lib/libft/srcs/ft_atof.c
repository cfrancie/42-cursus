/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 02:04:19 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/13 18:41:53 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long double	ft_atof(const char *str)
{
	long double	res;
	long double	dec;
	int		i;
	int		sign;

	i = 0;
	res = 0;
	dec = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		dec = dec * 10 + str[i++] - '0';
		res += dec / 10;
	}
	return (res * sign);
}
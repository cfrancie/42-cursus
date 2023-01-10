/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 02:04:19 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/10 17:48:02 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

#include <stdio.h>
long double	ft_atof(const char *str)
{
	long double	res;
	long double	pow;
	long double	sign;
	int			i;

	res = 0.0;
	pow = 1.0;
	sign = 1.0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while (ft_isdigit((unsigned char) str[i]))
		res = res * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
		++i;
	while (ft_isdigit((unsigned char) str[i]))
	{
		res = res * 10.0 + (str[i++] - '0');
		pow *= 10.0;
	}
	return (sign * res / pow);
}

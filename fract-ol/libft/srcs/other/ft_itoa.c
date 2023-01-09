/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:32:52 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/05 16:12:57 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int8_t	i;
	bool	neg;

	i = ft_intlen(n);
	neg = 0;
	if (n < 0)
		neg = 1;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--i] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

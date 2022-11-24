/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:55:28 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/23 19:40:33 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n)
	{
		n /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = ft_nbrlen(n);
	res = (char *)malloc((size_t)(sizeof(char) * (len + 1)));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (len--)
	{
		res[len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:55:28 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/07 18:18:28 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nbr;
	size_t	i;

	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	res = (char)malloc(sizeof(char) * ft_intlen(nbr));
	if (!res)
		return (NULL);
	i = 0;
	if (n < 0)
		res[i++] = '-';
	while (n)
	{
		res[i++] = (n % 10);
		n /= 10;
	}
	return (res);
}

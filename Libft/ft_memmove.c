/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:29:58 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/23 20:14:43 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	uint8_t	*d;
	uint8_t	*s;
	size_t	i;
	
	s = src;
	d = dest;
	if (!s ||!n)
		return (dest);
	if (d > s && d - s < (int)n)
	{
		i = n - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
		return (dest);
	}
	if (s > d && s - d < (int)n)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}

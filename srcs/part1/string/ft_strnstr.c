/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:21:52 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/07 14:59:11 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return (big);
	j = 0;
	while (big[i])
	{
		while (big[i + j] && (big[i + j] == little[j]) && len--)
			j++;
		if (little[j] == '\0' || big[i + j] == little[j] || len == 0)
			return (big + i);
		i++;
		j = 0;
		len = 0;x
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:45:00 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/07 11:49:34 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	s_dst;
	size_t	s_src;

	i = 0;
	j = 0;
	s_dst = ft_strlen(dst);
	s_src = ft_strlen(src);
	while (i < size && dst[i])
		i++;
	if (i == size)
		return (s_dst + i);
	while (i < size - 1 && src[j])
	{
		dst[i] = src[i];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (s_dst + s_src);
}

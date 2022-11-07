/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:55:44 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/07 17:53:24 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_addword(char *dst, const char *src, int start, char c)
{
	size_t	i;

	i = 0;
	while (dst[i])
	{
		if (dst[i])
		dst[i] = src[start];
		i++;
		start++;
	}
}

static size_t	ft_conterword(const char *str, char c)
{
	size_t	i;
	size_t	conter;

	conter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			++conter;
		i++;
	}
	return (conter);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char *) * (ft_conterword(s, c) + 1));
	if (!res)
		return (NULL);
	while (res[i])
	{
		if (res[i] == c && res[i + 1] != c)
		{

		}
		i++;
	}
	res[i] = '\n';
	return (res);
}

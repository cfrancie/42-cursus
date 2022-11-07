/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:21:04 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/07 21:55:32 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!res)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	k = ft_strlen(s1) - 1;
	while (k > i && ft_strchr(set, s1[k]))
		k--;
	while (i <= k)
		res[j++] = s1[i++];
	res[j] = '\0';
	return (res);
}

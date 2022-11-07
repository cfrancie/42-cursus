/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:14:38 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/07 21:48:19 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	tmp;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	tmp = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char)malloc(sizeof(char) * tmp);
	if (!res)
		return (NULL);
	tmp = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	tmp = 0;
	while (s2[i])
	{
		res[i] = s2[tmp];
		i++;
		tmp++;
	}
	res[i] = '\0';
	return (res);
}

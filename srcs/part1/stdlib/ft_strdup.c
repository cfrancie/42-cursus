/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:19:35 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/07 15:35:49 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *s)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char *) * ft_strlen(s));
	if (!res)
		return (NULL);
	i = 0;
	while (res[i])
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

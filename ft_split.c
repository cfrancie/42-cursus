/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:55:44 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/08 13:37:15 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		count;
	int		word;
	size_t	i;

	count = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			count++;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (count);
}

static char	*ft_addword(char const *s, size_t start, size_t finish)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (finish - start + 1));
	while (start < finish)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	int		tmp;

	res = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!s || !res)
		return (NULL);
	tmp = -1;
	i = 0;
	j = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && tmp < 0)
			tmp = i;
		else if ((s[i] == c || i == ft_strlen(s)) && tmp >= 0)
		{
			res[j] = ft_addword(s, tmp, i);
			tmp = -1;
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}

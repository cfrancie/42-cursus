/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:55:44 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/13 11:46:49 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && word == 0)
		{
			word = 1;
			i++;
		}
		else if (*s == c)
			word = 0;
		s++;
	}
	return (i);
}

static char	*ft_word_dup(char const *s, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (finish - start + 1));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;
	char	**split;

	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	k = -1;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] != c && k < 0)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			split[j] = ft_word_dup(s, k, i);
			k = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

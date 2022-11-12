/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:45:36 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/12 21:48:01 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_join_free(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

char	*ft_read_line(char *str)
{
	char		*res;
	size_t		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	res = ft_calloc(i + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			res[i] = '\n';
			return (res);
		}
		res[i] = str[i];
		i++;
	}
	return (res);
}

char	*ft_map(int fd, char *buffer)
{
	char	*tmp;
	int		r;

	if (!buffer)
		ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	r = 1;
	while (r > 0)
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			return (NULL);
		}
		tmp[r] = '\0';
		buffer = ft_join_free(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*ft_clear_line(char *str)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	res = ft_calloc(ft_strlen(str) - i, sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = ft_map(fd, str);
	if (!str)
		return (NULL);
	buffer = ft_read_line(str);
	if (!buffer)
		return (NULL);
	str = ft_clear_line(str);
	return (buffer);
}


// cc -Wall -Wextra -Werror -D BUFFER_SIZE=n
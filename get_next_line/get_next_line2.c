/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:12:32 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/14 00:14:21 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_endline(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_clear_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		buffer[i] = '\0';
		i++;
	}
	return (buffer);
}

char	*ft_clean_slash(char *str)
{
	// separates the array from '\n' and removes its characters from str
	char		*tmp;
	size_t		i;
	size_t		j;

	i = ft_endline(str);
	j = 0;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	while (j < i)
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	char		*buffer;
	ssize_t		r;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	r = read(fd, buffer, BUFFER_SIZE);
	if (r == -1)
		return (NULL);
	while (r > 0)
	{
		buffer[r] = '\0';
		if (!stash)
			stash = ft_strdup(buffer);
		else
			stash = ft_strjoin(stash, buffer);
		if (ft_endline(stash) > -1)
			break ;
		r = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (r == 0 && !stash)
		return (NULL);
	line = ft_strdup(stash);
	stash = ft_clean_slash_n(stash);
	return (line);
}

#include <stdio.h>
int main(void)
{
	int	fd = open("./test", O_RDONLY);
	char	*tmp = get_next_line(fd);
	printf("%s", tmp);
	return (0);
}

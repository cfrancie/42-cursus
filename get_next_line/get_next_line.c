/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:45:36 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/13 17:10:17 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clear_line(char *res, char *tmp)
{
	size_t	i;

	i = 0;
	while (tmp[i])
	{
		res[i] = tmp[i];
		if (tmp[i] == '\n')
			return (res);
		++i;
	}
	return (res);
}

char	*ft_map(int fd, char *buffer)
{
	char	*tmp;
	int		r;

	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	r = read(fd, tmp, BUFFER_SIZE + 1);
	if (r == -1)
	{
		free(tmp);
		free(buffer);
		return (NULL);
	}
	buffer = ft_strjoin(buffer, tmp);
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	tmp = ft_map(fd, tmp);
	if (!tmp)
		return (NULL);
	res = ft_clear_line(res, tmp);
	return (res);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=n

#include <stdio.h>
int main(void)
{
	int	fd = open("./test", O_RDONLY);
	char	*tmp = get_next_line(fd);
	printf("%d %s",fd, tmp);
	return (0);
}

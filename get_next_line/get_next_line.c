/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:45:36 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/11 18:11:56 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_lenline(int fd)
{
	int		r;
	char	a;
	size_t	res;

	res = 0;
	r = read(fd, &a, 1);
	while (r != -1)
	{
		if (r == 0 || a == '\n')
		{
			if (a == '\n')
				return (++res);
			return (res);
		}
		r = read(fd, &a, 1);
		++res;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*line;
	size_t		s_line;

	if (fd < 0)
		return (NULL);
	s_line = ft_lenline(fd);
	if (s_line == 0)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (ft_lenline(fd) + 1));
	if (!line)
		return (NULL);
}


// cc -Wall -Wextra -Werror -D BUFFER_SIZE=n
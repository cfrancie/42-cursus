/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:12:32 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/13 17:04:23 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_map_file(int fd, char *str)
{
	char	*tmp;
	size_t	i;
	int		r;

	tmp = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	r = read(fd, tmp, BUFFER_SIZE);
	if (r == 0)
		return (str);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
		{
			tmp[i] = '\n';
			str = ft_strjoin(str, tmp);
			free(tmp);
			return (str);
		}
		i++;
	}
	str = ft_strjoin(str, tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_map_file(fd, buffer);
	if (!buffer)
		return (NULL);
	return (buffer);
}

#include <stdio.h>
int main(void)
{
	int	fd = open("./test", O_RDONLY);
	char	*tmp = get_next_line(fd);
	printf("%s", tmp);
	return (0);
}

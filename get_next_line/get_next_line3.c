/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:49:47 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/13 18:09:35 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clear_tab(char *str, size_t end)
{
	char	*tmp;
	size_t	i;

	tmp = malloc(sizeof(char) * (end + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] && i <= end)
	{
		tmp[i] = str[i];
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

char	*ft_get_file(int fd)
{
	char	*tmp;
	size_t	i;
	int		r;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	r = read(fd, tmp, BUFFER_SIZE);
	if (r == -1)
		return (NULL);
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		if (tmp[i] == '\n')
			return (ft_clear_tab(tmp, i));
		i++;
	}
	return (ft_clear_tab(tmp, i));
}

char	*get_next_line(int fd)
{
	static char	**buffer;
	char		*line;

	buffer = ft_get_file(fd);
	if (!buffer)
		return (NULL);
	return (buffer);
}

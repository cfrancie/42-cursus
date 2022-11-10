/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:45:36 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/10 16:26:42 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	a;
	size_t	i;
	int		r;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	i = 0;
	r = read(fd, &a, 1);
	while (r != -1 || r != 0)
	{
		r = read(fd, &a, 1);
		if (a == '\n')
		{
			buffer[i] = a;
			return (buffer);
		}
		buffer[i++] = a;
	}
	return (buffer);
}

int	main(int argc, char const *argv[])
{
	char	*test;
	
	test = get_next_line(open(argv[1], O_RDONLY));
	
	return (0);
}

// gcc -Wall -Wextra -Werror -D BUFFER_SIZE=n
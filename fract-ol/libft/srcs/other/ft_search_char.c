/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:14:53 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/08 03:20:17 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

bool	ft_search_char(const char *s, char c)
{
	while (*s)
	{
		if (c == *s)
			return (true);
		s++;
	}
	return (false);
}

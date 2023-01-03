/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie@student.42.fr <cfrancie>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:12:30 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/02 21:09:30 by cfrancie@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	const char	*p = s;

	while (*p)
		p++;
	return (p - s);
}

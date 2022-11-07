/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:44:44 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/07 22:48:17 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    size_t  i;

    i = ft_strlen(s);
    while (i > 0 && s[i] != (char)c)
        i--;
    if (s[i] == (char)c)
        return ((char *)&s[i]);
    return (NULL);
}

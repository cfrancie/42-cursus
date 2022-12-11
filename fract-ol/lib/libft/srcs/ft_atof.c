/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 02:04:19 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/11 03:40:41 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double  ft_atof(const char *str)
{
    double  res;
    int     sign;
    double  power;

    res = 0;
    sign = 1;
    power = 1;
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r')
        str++;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    if (*str == '.')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        power *= 10;
        str++;
    }
    return (res * sign / power);
}
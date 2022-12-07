/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:27:10 by cfrancie          #+#    #+#             */
/*   Updated: 2022/12/07 20:31:10 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_atof(const char *nptr)
{
    double	ret;
    double dec = 0.1;
    int		sign;
    int		i;

    sign = 1;
    ret = 0;
    i = 0;
    while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
        || nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
        i++;
    if (nptr[i] == '+' || nptr[i] == '-')
    {
        if (nptr[i] == '-')
            sign *= -1;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        ret = ret * 10 + (nptr[i] - '0');
        i++;
    }
    if (nptr[i] == '.')
    {
        i++;
        // add the decimal part
        while (nptr[i] >= '0' && nptr[i] <= '9')
        {
            ret = ret + (nptr[i] - '0') * dec;
            dec *= 0.1;
            i++;
        }
    }
    return (ret * sign);
}

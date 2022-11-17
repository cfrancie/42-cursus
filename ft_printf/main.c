/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:45:16 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/16 15:57:10 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;

	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				ft_putnbr(va_arg(ap, char));
			else if (str[i] == 's')
				ft_putstr(va_arg(ap, char *));
			else if (str[i] == 'p')
				ft_putvoid(va_arg(ap, void *));
			else if (str[i] == 'd' || str[i] == 'i')
				ft_putint(va_arg(ap, int));
			else if (str[i] == 'x')
			
			
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (0);
}

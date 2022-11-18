/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:45:16 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/18 18:40:12 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_putall(const char *str, int i, va_list ap)
{
	if (!str || !str[i + 1])
		return (-1);
	if (str[i + 1] == '%')
		return (ft_putchar('%'));
	else if (str[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (str[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		return (ft_putint(va_arg(ap, int)));
	else if (str[i + 1] == 'p')
		return (ft_putvoid(va_arg(ap, void *), 0));
	else if (str[i + 1] == 'x')
		return (ft_puthexa(va_arg(ap, int), 0));
	else if (str[i + 1] == 'X')
		return (ft_puthexa(va_arg(ap, int), 1));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		res;
	ssize_t	tmp;
	int		i;

	va_start(ap, str);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_strindex(str[i + 1]))
		{
			tmp = ft_putall(str, i, ap);
			if (tmp == -1)
				return (-1);
			i++;
			res += tmp;
		}
		else
			res += ft_putchar(str[i]);
		i++;
	}
	return (res);
}

#include <stdio.h>
int main(void)
{
	int	i = ft_printf("%i\n", 42000);
	printf("%i\n", i);
	i = printf("%i\n", 42000);
	printf("%i\n", i);
	return 0;
}

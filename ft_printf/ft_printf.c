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

static int8_t	ft_putall(const char *str, int i)
{
	static va_list	g_ap;

	if (!str)
		return (0);
	if (str[i + 1] == '%')
		ft_putchar('%');
	else if (str[i + 1] == 'c')
		ft_putchar(va_arg(g_ap, int));
	else if (str[i + 1] == 's')
		ft_putstr(va_arg(g_ap, char *));
	else if (str[i + 1] == 'd')
		ft_putint(va_arg(g_ap, int));
	else if (str[i + 1] == 'p')
	{
		ft_putstr("0x");
		ft_putvoid(va_arg(g_ap, void *), 0);
	}
	else if (str[i + 1] == 'x')
		ft_puthexa(va_arg(g_ap, int), 0);
	else if (str[i + 1] == 'X')
		ft_puthexa(va_arg(g_ap, int), 1);
	else if (str[i] == '%')
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;

	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_putall(str, i) == 0)
				return (-1);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	return (i);
}

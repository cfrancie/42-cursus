/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:45:16 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/22 14:34:51 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_main(unsigned long n, int is_upper)
{
	if (!n)
		return (write(1, "(nil)", 5));
	ft_putstr("0x");
	return (ft_puthexa(n, is_upper) + 2);
}

int	ft_putnbr_main(long n, int is_unsigned)
{
	char	*conv;
	int		size;

	if (is_unsigned)
		conv = ft_itoa((unsigned int)n);
	else
		conv = ft_itoa(n);
	size = ft_strlen(conv);
	ft_putstr(conv);
	free(conv);
	return (size);
}

int	ft_putall(const char *str, va_list ap, int i)
{
	int		len;

	len = 0;
	if (str[i + 1] == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (str[i + 1] == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (str[i + 1] == 'p')
		len += ft_puthexa_main(va_arg(ap, unsigned long), 0);
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		len += ft_putnbr_main(va_arg(ap, int), 0);
	else if (str[i + 1] == 'u')
		len += ft_putnbr_main(va_arg(ap, unsigned int), 1);
	else if (str[i + 1] == 'x')
		len += ft_puthexa(va_arg(ap, unsigned int), 0);
	else if (str[i + 1] == 'X')
		len += ft_puthexa(va_arg(ap, unsigned int), 1);
	else if (str[i + 1] == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		res;
	int		i;

	if (!str)
		return (0);
	va_start(ap, str);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			res += ft_putall(str, ap, i);
			i++;
		}
		else
			res += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (res);
}

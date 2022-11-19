/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:45:16 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/20 00:57:14 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(const char c)
{
	return (write(1, &c, 1));
}

static int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

static int	ft_puthexa(unsigned long n, bool is_upper)
{
	char	*base;
	int	i;

	i = 0;
	base = "0123456789abcdef";
	if (is_upper)
		base = "0123456789ABCDEF";
	if (n >= 16)
		i += ft_puthexa(n / 16, is_upper);
	i += ft_putchar(base[n % 16]);
	return (i);
}

static int	ft_putall(const char *str, va_list ap, int i)
{
	int		len;

	len = 0;
	if (str[i] == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (str[i] == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (str[i] == 'p')
	{
		len += ft_putstr("0x");
		len += ft_puthexa((unsigned long)va_arg(ap, void *), 0);
	}
	else if (str[i] == 'd' || str[i] == 'i')
		len += ft_putstr(ft_itoa(va_arg(ap, int)));
	else if (str[i] == 'u')
		len += ft_putstr(ft_itoa(va_arg(ap, unsigned int)));
	else if (str[i] == 'x')
		len += ft_puthexa(va_arg(ap, unsigned int), 0);
	else if (str[i] == 'X')
		len += ft_puthexa(va_arg(ap, unsigned int), 1);
	else if (str[i] == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		res;
	int		i;

	va_start(ap, str);
	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
			res += ft_putall(str, ap, ++i);
		else
			res += ft_putchar(str[i]);
		++i;
	}
	va_end(ap);
	return (res);
}

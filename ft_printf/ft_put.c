/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:20:37 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/18 18:44:00 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

ssize_t	ft_putchar(const char c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_putstr(const char *str)
{
	return (write(1, &str, ft_strlen(str)));
}

ssize_t	ft_putint(int n)
{
	ssize_t	res;

	res = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		n = -n;
		res++;
	}
	if (n >= 10)
	{
		res++;
		ft_putint(n / 10);
	}
	ft_putchar(n % 10 + '0');
	res++;
	return (res);
}

ssize_t	ft_putvoid(void *ptr, int b_maj)
{
	unsigned long	nb;
	ssize_t			res;
	char			*base;

	res = 0;
	nb = (unsigned long)ptr;
	res += ft_putstr("0x");
	if (b_maj)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb == 0)
	{
		if (ft_putchar('0') == -1)
			return (-1);
		res++;
	}
	while (nb)
	{
		if (ft_putchar(base[nb % 16]) == -1)
			return (-1);
		nb /= 16;
		res++;
	}
	return (res);
}

ssize_t	ft_puthexa(int n, int b_maj)
{
	ssize_t	res;
	char	*base;

	res = 0;
	if (b_maj)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		res++;
		n = -n;
	}
	while (n)
	{
		if (ft_putchar(base[n % 16]) == -1)
			return (-1);
		n /= 16;
		res++;
	}
	return (res);
}

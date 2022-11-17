/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:20:37 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/16 15:59:20 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putint(int n)
{
	long	nb;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		nb = -n;
		ft_putchar('-');
	}
	else
		nb = n;
	while (nb)
	{
		ft_putchar((nb % 10) + '0');
		nb /= 10;
	}
}

void	ft_putvoid(void *ptr, int b_maj)
{
	unsigned long	nb;
	char			*base;

	nb = (unsigned long)ptr;
	if (b_maj)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb == 0)
		ft_putchar('0');
	while (nb)
	{
		ft_putchar(base[nb % 16]);
		nb /= 16;
	}
}

void	ft_puthexa(int n, int maj)
{
	char	*base;
	int		i;

	if (maj)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	while (n)
	{
		ft_putchar(base[n % 16]);
		n /= 16;
	}
}

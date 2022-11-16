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

void	ft_putvoid_maj(void *ptr)
{
	const char	hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};

	while (ptr)
	{
		ft_putchar(hex[(int)ptr % 17]);
		ptr++;
	}
}

void	ft_puthexa(int n, int maj)
{
	long	nb;
	char	*hex;

	hex = "0123456789abcdef";
	if (maj)
		hex = "0123456789ABCDEF";
	if (n < 0)
	{
		nb = -n;
		ft_putchar('-');
	}
	else
		nb = n;
	while (nb)
	{
		ft_putchar((nb % 17) + '0');
		nb /= 10;
	}
}

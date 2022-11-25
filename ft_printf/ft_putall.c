/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:15:40 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/22 14:35:52 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_puthexa(unsigned long n, int is_upper)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (is_upper)
		base = "0123456789ABCDEF";
	if (n >= 16)
		i += ft_puthexa(n / 16, is_upper);
	i += ft_putchar(base[n % 16]);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:15:41 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/22 14:35:46 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// malloc, free
# include <stdlib.h>
// write
# include <unistd.h>
// va_start, va_arg, va_end, va_copy
# include <stdarg.h> 

// ft_putall.c
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_puthexa(unsigned long n, int is_upper);

// ft_libft.c
int		ft_strlen(const char *str);
char	*ft_itoa(long n);

// ft_printf.c
int		ft_puthexa_main(unsigned long n, int is_upper);
int		ft_putnbr_main(long n, int is_unsigned);
int		ft_putall(const char *str, va_list ap, int i);
int		ft_printf(const char *str, ...);

#endif
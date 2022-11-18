/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:15:41 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/18 18:09:02 by cfrancie         ###   ########.fr       */
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
// size_t
# include <stdint.h>
# include <stdbool.h>

// tmp
# include <stdio.h>

// ft_printf.c
int		ft_printf(const char *str, ...);

// print.c
ssize_t	ft_putchar(const char c);
ssize_t	ft_putstr(const char *str);
ssize_t	ft_putint(int n);
ssize_t	ft_putvoid(void *ptr, int b_maj);
ssize_t	ft_puthexa(int n, int b_maj);

// utilitis
char	*ft_strchr(const char *s, int c);
int		ft_strindex(const char c);

#endif
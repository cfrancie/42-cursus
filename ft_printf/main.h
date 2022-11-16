/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:15:41 by cfrancie          #+#    #+#             */
/*   Updated: 2022/11/16 15:55:51 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

// malloc, free, 
# include <stdlib.h>
// write
# include <unistd.h>
// va_start, va_arg, va_end, va_copy
# include <stdarg.h> 
// size_t
# include <stdint.h>

// print.c
void	ft_putchar(const char c);
void	ft_putstr(const char *str);
void	ft_putint(int n);
void	ft_putvoid(void *ptr);

// util.c
int		ft_toupper(int c);

#endif
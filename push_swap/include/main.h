/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:37:23 by adl               #+#    #+#             */
/*   Updated: 2023/01/05 16:28:21 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

// includes write, read, malloc, free, exit
# include <unistd.h>
// includes open, close, read, write, 
# include <fcntl.h>
// includes malloc, free
# include <stdlib.h>

# include <stddef.h>
# include <stdbool.h>

typedef struct s_pile
{
	int				data;
	struct s_pile	*next;
}	t_pile;

typedef struct s_data
{
	t_pile	*a;
	t_pile	*b;
	size_t	size;
}	t_data;
// main.c

// check_args.c
void		put_swap_two(int i, t_data *data);
void		put_swap_one(int i, t_data *data);
bool		check_double(t_data *data);
void		exit_andfree(t_data *data);

// swap_00.c
void		ft_sa(t_data *data, bool print);
void		ft_sb(t_data *data, bool print);
void		ft_ss(t_data *data);
void		ft_pa(t_data *data);
void		ft_pb(t_data *data);

// swap_01.c
void		ft_ra(t_data *data, bool print);
void		ft_rb(t_data *data, bool print);
void		ft_rr(t_data *data);
void		ft_rra(t_data *data, bool print);
void		ft_rrb(t_data *data, bool print);

// swap_02.c
void		ft_rrr(t_data *data);

// utils.c
size_t		ft_strlen(const char *str);
void		ft_putstr(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_atoi(const char *nptr);
t_pile		*ft_lstnew(int data);
t_pile		*ft_lstlast(t_pile *lst);

#endif
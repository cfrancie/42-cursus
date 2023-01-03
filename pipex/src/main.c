/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie@student.42.fr <cfrancie>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:10:07 by adl               #+#    #+#             */
/*   Updated: 2023/01/02 21:36:11 by cfrancie@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int	main(int argc, char **argv)
{
	if (argc != 5)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		return (1);
	}
	ft_putstr_fd(argv[0], 1);
	return (0);
}

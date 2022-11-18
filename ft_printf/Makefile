# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 14:18:42 by cfrancie          #+#    #+#              #
#    Updated: 2022/11/18 18:06:57 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
NAME		= libftprintf.a

SRCS		= ft_printf.c ft_put.c


OBJS		= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all bonus clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 02:25:20 by cfrancie          #+#    #+#              #
#    Updated: 2022/11/26 02:28:16 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= fdf

SRCS	=
OBJS	= $(SRCS:.c=.o)

SRCS_DIR	= $(addprefix srcs/, $(SRCS))
OBJS_DIR	= $(addprefix objs/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_DIR)
	@echo "\033[32m[ ✔ ] %s\033[0m" $(NAME)

$(OBJS_DIR): $(SRCS_DIR)
	@mkdir -p objs
	@$(CC) $(CFLAGS) -c $(SRCS_DIR)
	@mv $(OBJS) objs
	@echo "\033[32m[ ✔ ] %s\033[0m" $(OBJS)

clean:
	@rm -rf objs
	@echo "\033[31m[ ✔ ] %s\033[0m" $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[ ✔ ] %s\033[0m" $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 19:04:31 by cfrancie          #+#    #+#              #
#    Updated: 2023/01/04 18:19:32 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ./srcs/
OBJS	= ./objs/

CFILE	= $(shell find $(SRCS) -name "*.c")
OFILE	= $(CFILE:$(SRCS)%.c=$(OBJS)%.o)

all: $(NAME)

$(NAME): $(OFILE)
	@ar rc $(NAME) $(OFILE)
	@ranlib $(NAME)

$(OBJS)%.o: $(SRCS)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "\033[32m[`expr $$(expr $$(find $(OBJS) -name "*.o" | wc -l) \* 100) / $$(find $(SRCS) -name "*.c" | wc -l)`%]\033[0m Compilation de \033[33m$<\033[0m"

clean:
	@rm -rf $(OBJS)
	@echo "clean: $(OBJS) deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "fclean: $(NAME) deleted"

debug: fclean
	@$(MAKE) CFLAGS="-g -fsanitize=address -g3 -fno-omit-frame-pointer" all

re: fclean all

.PHONY: all clean fclean debug re

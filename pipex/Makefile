# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 20:02:10 by adl               #+#    #+#              #
#    Updated: 2023/01/07 01:20:34 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC 		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ./srcs/
OBJS	= ./objs/
LIBFT	= ./lib/libft
PRINTF	= ./lib/ft_printf

CFILE	= ${SRCS}main.c
OFILE	= $(CFILE:$(SRCS)%.c=$(OBJS)%.o)

all: $(NAME)

$(NAME): $(OFILE)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@$(CC) $(CFLAGS) -o $(NAME) $(OFILE) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a

$(OBJS)%.o: $(SRCS)%.c
	@mkdir -p $(OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "\033[32m[`expr $$(expr $$(find $(OBJS) -name "*.o" | wc -l) \* 100) / $$(find $(SRCS) -name "*.c" | wc -l)`%]\033[0m Compilation of \033[33m$<\033[0m"

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(PRINTF)
	@rm -rf $(OBJS)
	@echo -e "\033[31m$(OBJS) deleted\033[0m"

fclean: clean
	@make fclean -C $(LIBFT)
	@make fclean -C $(PRINTF)
	@rm -f $(NAME)
	@echo -e "\033[31m$(NAME) deleted\033[0m"

re: fclean all
	@echo -e "\033[32m$(NAME) recompiled\033[0m"

.PHONY: all clean fclean re

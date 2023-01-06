# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 21:35:32 by cfrancie          #+#    #+#              #
#    Updated: 2023/01/06 21:07:18 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -O3 -g3

SRCS 	= ./srcs/
OBJS 	= ./objs/
LIBFT 	= ../libft/
LIBX	= ./lib/minilibx-linux

CFILE	= ${SRCS}draw.c ${SRCS}generate.c ${SRCS}input.c ${SRCS}main.c

OFILE	= $(CFILE:$(SRCS)%.c=$(OBJS)%.o)

all: $(NAME)

$(NAME): $(OFILE) ../libft/libft.a lib/minilibx-linux/libmlx.a
	@$(CC) $(CFLAGS) -o $(NAME) $(OFILE) -L $(LIBFT) -lft -L $(LIBX) -lmlx -lXext -lX11 -lm -lbsd
	@echo "\033[32m----------------[\033[33m$(NAME)\033[32m is compiled]----------------\033[0m"

../libft/libft.a:
	@make -C $(LIBFT)

lib/minilibx-linux/libmlx.a:
	@make -C $(LIBX)

$(OBJS)%.o: $(SRCS)%.c
	@mkdir -p $(OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ -lmlx -lXext -lX11 -lm -lbsd -I $(LIBFT) -I $(LIBX)
	@echo "\033[32m[`expr $$(expr $$(find $(OBJS) -name "*.o" | wc -l) \* 100) / $$(find $(SRCS) -name "*.c" | wc -l)`%]\033[0m Compilation de \033[33m$<\033[0m"

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(LIBX)
	@rm -rf $(OBJS)
	@echo "\033[31m$(OBJS) deleted\033[0m"

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) deleted\033[0m"

re: fclean all 

.PHONY: all clean fclean re
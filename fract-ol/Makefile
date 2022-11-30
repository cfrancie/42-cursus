# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 02:24:15 by cfrancie          #+#    #+#              #
#    Updated: 2022/11/29 20:37:25 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
XFLAGS	= -lmlx -framework OpenGL -framework AppKit

LIBFT	= libft/libft.a
MLX		= minilibx-linux/libmlx.a

SRCS_DIR	= srcs
OBJS_DIR	= objs
INCS_DIR	= includes

SRCS	= fract_ol.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@make -C minilibx-linux
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)
	@echo "Compilation done"
	
%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR)
	@echo "Compilation of $<"

clean:
	@make clean -C libft
	@make clean -C minilibx-linux
	@rm -f $(OBJS)
	@echo "Clean done"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "Fclean done"

re: fclean all
	@echo "Re done"

.PHONY: all clean fclean re
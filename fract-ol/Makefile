# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 02:24:15 by cfrancie          #+#    #+#              #
#    Updated: 2022/11/28 02:49:22 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol
CC      = gcc
CFLAGS  = -Wall -Werror -Wall

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = ./minilibx-linux/
MLX = $(MLX_DIR)libmlx.a

SRCS_DIR = srcs/
SRCS = calculator.c color.c fract_ol.c zoom.c

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) -Imlx -lXext -lX11 -lm -lz
	@echo "Compilation done"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -rf $(OBJS_DIR)
	@echo "Clean done"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "Fclean done"

re: fclean all

.PHONY: all clean fclean re

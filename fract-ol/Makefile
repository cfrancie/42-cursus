# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 02:24:15 by cfrancie          #+#    #+#              #
#    Updated: 2022/12/07 21:28:44 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fractol
CC			= gcc -O3
CFLAGS		= -Wall -Wextra -Werror

MLX_PATH	= ./minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(addprefix $(MLX_PATH), $(MLX_NAME))

LIBFT_PATH	= ./libft/
LIBFT_NAME	= libft.a
LIBFT		= $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

INC			= -I ./includes/ -I $(LIBFT_PATH) -I $(MLX_PATH)

SRCS_PATH	= ./srcs/
SRC			= fract_ol.c input.c print_pixel.c
SRCS		= $(addprefix $(SRCS_PATH), $(SRC))

OBJS_PATH	= ./objs/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJS_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@echo "Compiling $<"
	
$(OBJS): $(OBJS_PATH)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)
	
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(MLX) $(LIBFT) -o $(NAME) -lXext -lX11 -lm

clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJS_PATH)
	@echo "Clean done"

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo "Fclean done"

re: fclean all

.PHONY: all clean fclean re
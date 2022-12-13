# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 18:21:26 by cfrancie          #+#    #+#              #
#    Updated: 2022/12/13 18:40:51 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fractol
CC			= gcc -O3
CFLAGS		= -Wall -Wextra -Werror

MLX_PATH	= ./lib/minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(addprefix $(MLX_PATH), $(MLX_NAME))

LIBFT_PATH	= ./lib/libft/
LIBFT_NAME	= libft.a
LIBFT		= $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

INC			= -I ./inc/ -I $(LIBFT_PATH)/ -I $(MLX_PATH)/

SRCS_PATH	= ./src/
SRC			= main.c input.c draw.c generate.c
SRCS		= $(addprefix $(SRCS_PATH), $(SRC))

OBJS_PATH	= ./obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJS_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $
	
$(OBJS): $(OBJS_PATH)

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(MLX):
	make -sC $(MLX_PATH)

$(LIBFT):
	make -sC $(LIBFT_PATH)
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) $(MLX) $(LIBFT) -o $(NAME) -lXext -lX11 -lm
	echo "Compilation done"

clean:
	make -C $(MLX_PATH) clean
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS_PATH)
	echo "Clean done"

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	echo "Fclean done"

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 02:24:15 by cfrancie          #+#    #+#              #
#    Updated: 2022/12/04 08:25:56 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

LIBFT		= libft/libft.a
MLX			= minilibx-linux/libmlx.a

SCRS_DIR	= srcs
OBJS_DIR	= objs

SRCS_NAME	= fract_ol.c keyboard.c zoom.c
OBJS_NAME	= $(SRCS:.c=.o)

OBJS_NAME	= $(SRCS_NAME:.c=.o)
OBJSB_NAME	= $(BONUS_NAME:.c=.o)

SRCS		= $(addprefix $(SCRS_DIR)/, $(SRCS_NAME))
OBJS		= $(addprefix $(OBJS_DIR)/, $(OBJS_NAME))

all: $(NAME)
	@echo "Compilation done"

$(NAME): $(OBJS)
	@make -C libft
	@make -C minilibx-linux
	@ar rc $(NAME) $(OBJS)
	@echo "Compilation done"

$(OBJS_DIR)/%.o: $(SCRS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
	@echo "Compilation of $<"

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -C libft
	@make clean -C minilibx-linux
	@echo "Clean done"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C minilibx-linux
	@echo "Fclean done"

re: fclean all
	@echo "Re done"

.PHONY: all clean fclean re bonus
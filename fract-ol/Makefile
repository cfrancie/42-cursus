# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 02:24:15 by cfrancie          #+#    #+#              #
#    Updated: 2022/11/27 19:33:29 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol
CC      = gcc
CFLAGS  = -Wall -Werror -Wall

LIBX	= libmlx.a
LIBFT	= libft.a

LIBX_P  = srcs/minilibx-linux/
LIBFT_P = srcs/libft/

LIBX_F  = $(addprefix $(LIBX_P), $(LIBX))
LIBFT_F = $(addprefix $(LIBFT_P), $(LIBFT))

INC     = -I ./includes/ -I ./libft/ -I ./minilibx-linux/

SRCS	= fract_ol.c color.c calculator.c
SRCS_P	= srcs/

OBJS	= $(SRCS:.c=.o)
OBJS_P	= objs/

OBJS_F	= $(addprefix $(OBJS_P), $(OBJS))
SRCS_F	= $(addprefix $(SRCS_P), $(SRCS))

all: $(NAME) $(LIBX_F) $(LIBFT_F)

$(NAME): $(OBJS_F)
	@make -C $(LIBFT_P)
	@make -C $(LIBX_P)
	@$(CC) -o $(NAME) $(OBJS_F) $(LIBX_F) $(LIBFT_F) $(INC) -lXext -lX11 -lm

$(OBJS_P)%.o: $(SRCS_P)%.c
	@mkdir -p $(OBJS_P)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJS_P)
	@make clean -C $(LIBFT_P)
	@make clean -C $(LIBX_P)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_P)
	@make clean -C $(LIBX_P)

re: fclean all

.PHONY: all clean fclean re

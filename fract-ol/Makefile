# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 21:35:32 by cfrancie          #+#    #+#              #
#    Updated: 2022/12/13 22:04:03 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INC		= -I./include/ -I./minilibx-linux
OBJDIR	= ./obj/
SRCDIR	= ./src/

NAME	= fractol

SRC		= main.c \
		input.c \
		generate.c \
		draw.c \
		utility.c

SRCS	= $(addprefix $(SRCDIR), $(SRC))

OBJ		= $(SRC:.c=.o)

OBJS	= $(addprefix $(OBJDIR), $(OBJ))

LIBX	= ./lib/minilibx-linux

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBX)
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS) -L$(LIBX) -lmlx -lXext -lX11 -lm -lbsd -g3 -O3
	@echo "compilation of $(NAME) done"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "compilation of $@ done"

clean:
	@make clean -C $(LIBX)
	@rm -rf $(OBJDIR)
	@echo "clean done"

fclean: clean
	@make clean -C $(LIBX)
	@rm -f $(NAME)
	@echo "fclean done"

re: fclean all
	@echo "re done"

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adl <adl@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 14:29:24 by adl               #+#    #+#              #
#    Updated: 2022/12/24 00:53:36 by adl              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INC		= -I./include/
OBJDIR	= ./obj/
SRCDIR	= ./src/

NAME	= push_swap

SRC		= main.c \
		check_args.c \
		swap_00.c \
		swap_01.c \
		swap_02.c \
		sorter.c \
		utils.c \

SRCS	= $(addprefix $(SRCDIR), $(SRC))

OBJ		= $(SRC:.c=.o)

OBJS	= $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)
	@echo "compilation of $(NAME) done"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo "compilation of $@ done"

clean:
	@rm -rf $(OBJDIR)
	@echo "clean done"

fclean: clean
	@rm -f $(NAME)
	@echo "fclean done"

re: fclean all
	@echo "re done"

.PHONY: all clean fclean re
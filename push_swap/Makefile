# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 14:29:24 by adl               #+#    #+#              #
#    Updated: 2023/01/10 02:53:28 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
OBJDIR	= ./objs/
SRCDIR	= ./srcs/

NAME	= push_swap

SRC		= main.c \
		check_args.c \
		swap_00.c \
		swap_01.c \
		swap_02.c \
		utils.c \
		utils2.c \

SRCS	= $(addprefix $(SRCDIR), $(SRC))

OBJ		= $(SRC:.c=.o)

OBJS	= $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I ./includes/
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
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie@student.42.fr <cfrancie>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 20:02:10 by adl               #+#    #+#              #
#    Updated: 2023/01/02 21:37:04 by cfrancie@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INC		= -I./include/
OBJDIR	= ./obj/
SRCDIR	= ./src/

NAME	= pipex

SRC		= main.c

SRCS	= $(addprefix $(SRCDIR), $(SRC))

OBJ		= $(SRC:.c=.o)

OBJS	= $(addprefix $(OBJDIR), $(OBJ))

LIB		= libft

LIBS	= $(addprefix -L./lib/, $(LIB))

# variable for % of compilation
PERCENT	= 0
NB_FILES= $(words $(SRC))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./lib/libft
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIBS) -o $(NAME)
	@echo "\033[32m$(NAME) compiled\033[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@$(eval PERCENT=$(shell echo $$(($(PERCENT)+100/$(NB_FILES)))))
	@echo -ne "\r\033[32mCompilation: $(PERCENT)%\033[0m"

clean:
	@make clean -C ./lib/libft
	@rm -rf $(OBJDIR)
	@echo -ne "\r\033[31m$(NAME) objects deleted\033[0m"

fclean: clean
	@make fclean -C ./lib/libft
	@rm -f $(NAME)
	@echo -ne "\r\033[31m$(NAME) deleted\033[0m"

re: fclean all

.PHONY: all clean fclean re
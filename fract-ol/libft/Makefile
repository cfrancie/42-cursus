# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 19:04:31 by cfrancie          #+#    #+#              #
#    Updated: 2023/01/11 00:23:52 by cfrancie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ./srcs/
OBJS	= ./objs/

CFILE	= $(SRCS)ctype.h/ft_isalnum.c \
$(SRCS)ctype.h/ft_isalpha.c \
$(SRCS)ctype.h/ft_isascii.c \
$(SRCS)ctype.h/ft_isblank.c \
$(SRCS)ctype.h/ft_iscntrl.c \
$(SRCS)ctype.h/ft_isdigit.c \
$(SRCS)ctype.h/ft_isgraph.c \
$(SRCS)ctype.h/ft_isprint.c \
$(SRCS)ctype.h/ft_ispunct.c \
$(SRCS)ctype.h/ft_isspace.c \
$(SRCS)ctype.h/ft_isxdigit.c \
$(SRCS)ctype.h/ft_tolower.c \
$(SRCS)ctype.h/ft_toupper.c \
$(SRCS)other/bonus/ft_lstadd_back.c \
$(SRCS)other/bonus/ft_lstadd_front.c \
$(SRCS)other/bonus/ft_lstclear.c \
$(SRCS)other/bonus/ft_lstdelone.c \
$(SRCS)other/bonus/ft_lstiter.c \
$(SRCS)other/bonus/ft_lstlast.c \
$(SRCS)other/bonus/ft_lstmap.c \
$(SRCS)other/bonus/ft_lstnew.c \
$(SRCS)other/bonus/ft_lstsize.c \
$(SRCS)other/ft_abs.c \
$(SRCS)other/ft_intlen.c \
$(SRCS)other/ft_itoa.c \
$(SRCS)other/ft_ldabs.c \
$(SRCS)other/ft_max.c \
$(SRCS)other/ft_min.c \
$(SRCS)other/ft_putchar.c \
$(SRCS)other/ft_putchar_fd.c \
$(SRCS)other/ft_putendl_fd.c \
$(SRCS)other/ft_putnbr_fd.c \
$(SRCS)other/ft_search_char.c \
$(SRCS)other/ft_putstr.c \
$(SRCS)other/ft_putstr_fd.c \
$(SRCS)other/ft_split.c \
$(SRCS)other/ft_striteri.c \
$(SRCS)other/ft_strjoin.c \
$(SRCS)other/ft_strmapi.c \
$(SRCS)other/ft_strtrim.c \
$(SRCS)other/ft_substr.c \
$(SRCS)stdlib.h/ft_atof.c \
$(SRCS)stdlib.h/ft_atoi.c \
$(SRCS)stdlib.h/ft_atol.c \
$(SRCS)stdlib.h/ft_calloc.c \
$(SRCS)stdlib.h/ft_itoa.c \
$(SRCS)stdlib.h/ft_strdup.c \
$(SRCS)string.h/ft_bzero.c \
$(SRCS)string.h/ft_memchr.c \
$(SRCS)string.h/ft_memcmp.c \
$(SRCS)string.h/ft_memcpy.c \
$(SRCS)string.h/ft_memmove.c \
$(SRCS)string.h/ft_memset.c \
$(SRCS)string.h/ft_strcat.c \
$(SRCS)string.h/ft_strchr.c \
$(SRCS)string.h/ft_strcmp.c \
$(SRCS)string.h/ft_strlcat.c \
$(SRCS)string.h/ft_strlcpy.c \
$(SRCS)string.h/ft_strlen.c \
$(SRCS)string.h/ft_strncat.c \
$(SRCS)string.h/ft_strncmp.c \
$(SRCS)string.h/ft_strncpy.c \
$(SRCS)string.h/ft_strndup.c \
$(SRCS)string.h/ft_strnstr.c \
$(SRCS)string.h/ft_strrchr.c \
$(SRCS)string.h/ft_strstr.c \

OFILE	= $(CFILE:$(SRCS)%.c=$(OBJS)%.o)

all: $(NAME)

$(NAME): $(OFILE)
	@ar rc $(NAME) $(OFILE)
	@ranlib $(NAME)
	@echo -e "\033[32m----------------[\033[33m$(NAME)\033[32m is compiled]----------------\033[0m"

$(OBJS)%.o: $(SRCS)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "\033[32m[`expr $$(expr $$(find $(OBJS) -name "*.o" | wc -l) \* 100) / $$(find $(SRCS) -name "*.c" | wc -l)`%]\033[0m Compilation of \033[33m$<\033[0m"

clean:
	@rm -rf $(OBJS)
	@echo -e "\033[31m----------------[\033[33m$(OBJS)\033[31m deleted]----------------\033[0m"


fclean: clean
	@rm -f $(NAME)
	@echo -e "\033[31m----------------[\033[33m$(NAME)\033[31m deleted]----------------\033[0m"

re: fclean all

.PHONY: all clean fclean re

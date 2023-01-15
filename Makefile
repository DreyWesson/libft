# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doduwole <doduwole@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 15:58:46 by doduwole          #+#    #+#              #
#    Updated: 2023/01/15 19:50:25 by doduwole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c		\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_split.c		\
		ft_strchr.c		\
		ft_strncmp.c	\
		ft_strdup.c		\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strlen.c		\
		ft_strmapi.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_tolower.c	\
		ft_toupper.c

BONUS_SRC = t_list.c

HEAD = ./

OBJ = 	ft_atoi.o		\
		ft_bzero.o		\
		ft_calloc.o		\
		ft_isalnum.o	\
		ft_isalpha.o	\
		ft_isascii.o	\
		ft_isdigit.o	\
		ft_isprint.o	\
		ft_itoa.o		\
		ft_memchr.o		\
		ft_memcmp.o		\
		ft_memmove.o	\
		ft_memset.o		\
		ft_memcpy.o		\
		ft_putchar_fd.o	\
		ft_putstr_fd.o	\
		ft_putendl_fd.o	\
		ft_putnbr_fd.o	\
		ft_split.o		\
		ft_strchr.o		\
		ft_strncmp.o	\
		ft_strdup.o		\
		ft_striteri.o	\
		ft_strjoin.o	\
		ft_strlcat.o	\
		ft_strlcpy.o	\
		ft_strlen.o		\
		ft_strmapi.o	\
		ft_strnstr.o	\
		ft_strrchr.o	\
		ft_strtrim.o	\
		ft_substr.o		\
		ft_tolower.o	\
		ft_toupper.o	\
		t_list.o

BONUS_OBJ = t_list.o

ECHO = echo

all : $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@$(ECHO) "✅" $@

%.o: %.c
	@gcc -Wall -Wextra -Werror -I $(HEAD) -o $@ -c $<
	@$(ECHO) "✅" $@

clean:
	@echo "Remove .o  ..."
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "Remove lib ..."
	@/bin/rm -f $(NAME)

re: fclean all

bonus:	$(BONUS_OBJS)
		ar rcs $(NAME) $(BONUS_OBJS)

# .PHONY:	all clean fclean re bonus
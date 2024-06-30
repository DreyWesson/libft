# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oduwoledare <oduwoledare@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 18:56:51 by oduwoledare       #+#    #+#              #
#    Updated: 2023/10/29 20:42:53 by oduwoledare      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Account


# FLAGS
CC = c++
CFLAGS = -Werror -Wall -Wextra -std=c++98 -pedantic -fsanitize=address


# Del
RM = rm -rf


# DIRECTORIES
SRC =	$(wildcard *.cpp **/*.cpp **/*/*.cpp)
OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc
OBJS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)


# COLOURS
NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
WARNING='\033[33m'


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $@ $(CFLAGS)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)/%.o: %.cpp 
	@echo $(CURSIVE)$(GRAY) "     - Building $<" $(NONE)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJ_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Object files removed" $(NONE)

fclean: clean
	@rm -f $(NAME)
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re: fclean all

.PHONY: all clean fclean re

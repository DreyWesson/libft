# Variables
NAME = serialize

CC = c++
CFLAGS = -Werror -Wall -Wextra -std=c++98

RM = rm -rf
MKDIR = mkdir -p
OBJ_DIR = obj
DEP_DIR = dep
INC_DIR = inc

DEPFLAGS = -MMD -MP -MF $(DEP_DIR)/$*.d

SRC = $(wildcard *.cpp **/*.cpp **/*/*.cpp) 
OBJS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

NONE='\033[0m'
GREEN='\033[32m'
CURSIVE='\033[3m'
GRAY='\033[2;37m'

all: $(NAME)

-include $(wildcard $(DEP_DIR)/**/*.d)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)/%.o: %.cpp
	@echo $(CURSIVE) "     - Building $<" $(NONE)
	@$(MKDIR) $(@D)
	@$(MKDIR) $(DEP_DIR)/$(patsubst %/,%,$(dir $<))
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS) $(OBJ_DIR) $(DEP_DIR) > /dev/null || true
	@echo $(CURSIVE)$(GRAY) "     - Object files, dependencies, and $(NAME) removed" $(NONE)

fclean: clean
	@$(RM) $(NAME) > /dev/null || true
	@echo $(CURSIVE)$(GRAY) "     - $(NAME) removed" $(NONE)

re: fclean all

.PHONY: all clean fclean re

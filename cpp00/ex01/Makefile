NAME		= phonebook

SRC_FILES	=	phonebook.cpp	\
				pb_utils.cpp

SRC_DIR	= src
OBJ_DIR = obj
INC_DIR	= include

OBJ_FILES	= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))
DEP_FILES	= $(OBJ_FILES:.o=.d)

CC		= c++
CFLAGS	= -Wall -Wextra -Werror -MMD -MP

all: objdir $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@

objdir:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

-include $(DEP_FILES)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

fsan: CFLAGS += -fsanitize=address
debug: CFLAGS += -g
fsan debug: re

.PHONY: all objdir clean fclean re fsan debug
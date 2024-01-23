NAME	:= sed

SRC_FILES	:=	main.cpp

SRC_DIR	:= src
OBJ_DIR	:= obj
INC_DIR	:= include

OBJ_FILES	:= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))
DEP_FILES	:= $(OBJ_FILES:.o=.d)

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP
IFLAGS	:= -I$(INC_DIR)
DFLAGS	:=

_DEBUG := 0
ifeq ($(_DEBUG), 1)
	DFLAGS += -g3 -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(DFLAGS) $^ -o $@ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

-include $(DEP_FILES)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re
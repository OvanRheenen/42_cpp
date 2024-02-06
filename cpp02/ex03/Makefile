NAME	:= bsp

SRC_FILES	:=	main.cpp	\
				bsp.cpp		\
				Fixed.cpp	\
				Point.cpp

SRC_DIR	:= src
OBJ_DIR	:= obj
INC_DIR	:= include

OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))
DEP_FILES := $(OBJ_FILES:.o=.d)

CC		:= c++
CFLAGS	:= -Wall -Wextra -Werror -MMD -MP -std=c++98
IFLAGS	:= -I$(INC_DIR)
DFLAGS	:=

_DEBUG := 0
ifeq ($(_DEBUG), 1)
	DFLAGS += -g3 -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(DFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

-include $(DEP_FILES)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
NAME	:= create_log

SRC_FILES	:=	Account.cpp	\
				tests.cpp

SRC_DIR	:= src
OBJ_DIR	:= obj
INC_DIR	:= include

OBJ_FILES	:= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))
DEP_FILES	:= $(OBJ_FILES:.o=.d)

CC		:= c++

CFLAGS	:= -Wall -Wextra -Werror -MMD -MP -std=c++98
IFLAGS	:= -I$(INC_DIR)
DFLAGS	:=

ifdef DEBUG
	DFLAGS += -g3 -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(DFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

-include $(DEP_FILES)

debug:
	$(MAKE) DEBUG=1 all

log: all
	./$(NAME) > mylogfile.log

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug log clean fclean re
NAME = BSDL
CC = g++ -std=c++17
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llib/SDL/lib -lSDL2 -lm
RM = rm -f

SRC_DIR = src/
SRC_FILES = $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJ_DIR = objs/
OBJS = $(SRC_FILES:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c $< -o $@

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(OBJS) $(LDFLAGS) -o $@ 
			@echo "\r\033[33mDONE!\033[0m         "

clean:
			@$(RM) -r $(OBJ_DIR)

fclean: clean
			@$(RM) $(NAME)

re: fclean all

.PHONY: 	all clean fclean re

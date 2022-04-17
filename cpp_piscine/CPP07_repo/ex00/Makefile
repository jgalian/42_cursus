NAME =	templates

SRC =	main.cpp

OBJ = $(SRC:.cpp=.o)
INC = -I.

CXXFLAGS = -Wall -Wextra -Werror -g -Wshadow -std=c++98 $(INC) $(SANITIZE) $(DEBUG)
CXX = clang++

SANITIZE =
SANITIZE_FLAGS = -g3 -fsanitize=address
DEBUG =
DEBUG_FLAGS = -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

sanitize: SANITIZE += $(SANITIZE_FLAGS)
sanitize: fclean all

debug: DEBUG += $(DEBUG)
debug: fclean all

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = easyfind
override CXX = c++
override CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
override SRC = main.cpp NotFoundException.cpp
override OBJ = main.o NotFoundException.o
override RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

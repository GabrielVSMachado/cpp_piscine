NAME = iter
override CXX = c++
override CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
override RM = rm -f
override SRC = main.cpp
override OBJ = main.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = bsp
override CXX = c++
override CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
override RM = rm -f
override SRC = Fixed.cpp main.cpp Point.cpp bsp.cpp
override OBJ = $(SRC:%.cpp=%.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

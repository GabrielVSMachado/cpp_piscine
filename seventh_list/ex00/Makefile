NAME = types
override CXX = c++
override CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -Wconversion
override SRC = main.cpp Types.cpp
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

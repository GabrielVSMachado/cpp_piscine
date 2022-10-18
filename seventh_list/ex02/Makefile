NAME = dynamicCheck
override CXX = c++
override CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -Wconversion
override RM = rm -f
override SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp
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

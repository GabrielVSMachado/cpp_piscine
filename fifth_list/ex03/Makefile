NAME = interface_and_recap
override CXX = c++
override CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
override SRC = main.cpp Character.cpp AMateria.cpp Ice.cpp Cure.cpp
override OBJ = $(SRC:%.cpp=%.o)
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

NAME = clapTrap_scavTrap_fragTrap
override CXX = c++
override CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -Wshadow
override RM = rm -f
override SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
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

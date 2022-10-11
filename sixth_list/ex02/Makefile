NAME = bureaucrat
override CXX = c++
override CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -Wshadow
override RM = rm -f
override SRC = main.cpp\
	AForm.cpp\
	BureaucracyConstitution.cpp\
	Bureaucrat.cpp\
	ShrubberyCreationForm.cpp

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

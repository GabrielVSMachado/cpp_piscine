NAME = bureaucrat
override CXX = c++
override CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -Wshadow
override RM = rm -f
override SRC = main.cpp\
	Form.cpp\
	Exceptions.cpp\
	Bureaucrat.cpp\
	ShrubberyCreationForm.cpp\
	RobotomyRequestForm.cpp\
	PresidentialPardomForm.cpp

override OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ)
	$(RM) *_shrubbery

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

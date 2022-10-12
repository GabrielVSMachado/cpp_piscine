override NAME = megaphone
override CXXFLAGS = -std=c++98 -Wall -Wextra -Werror
override CXX = c++

OBJ = megaphone.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	$(RM) megaphone.o

fclean: clean
	$(RM) $(NAME)

test: all
	@echo
	./$(NAME) "shhhhh... I think the students are asleep..."

	@echo
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."

	@echo
	./$(NAME)

re: clean all

override NAME = megaphone
override CFLAGS = -std=c++98 -Wall -Wextra -Werror -Wno-used
override CC = c++

OBJ = megaphone.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) megaphone.o

fclean: clean
	$(RM) $(NAME)

test: all
	@echo "shhhhh... I think the students are asleep..."
	@echo
	./$(NAME) "shhhhh... I think the students are asleep..."

	@echo
	@echo Damnit " ! " "Sorry students, I thought this thing was off."
	@echo
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."

	@echo
	./$(NAME)

re: clean all

NAME = Moar_Brainz
override CC = c++
override CFLAGS = -std=c++98 -Wall -Wextra -Werror

override define SRC
	main.cpp
	Zombie.cpp
	zombieHorde.cpp
endef

override OBJ = $(SRC:%.cpp=%.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

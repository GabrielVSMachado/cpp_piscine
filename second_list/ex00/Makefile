NAME = zombie
override CC = c++
override CFLAGS = -std=c++98 -Wall -Wextra -Werror -g3

override define SRC
	main.cpp
	Zombie.cpp
	randomChump.cpp
	newZombie.cpp
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

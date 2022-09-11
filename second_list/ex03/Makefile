NAME = Unnecessary_Violence
override CC = c++
override CFLAGS = -std=c++98 -Wall -Werror -Wextra
override define SRC
	main.cpp
	Weapon.cpp
	HumanA.cpp
	HumanB.cpp
endef
override RM = rm -f

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

NAME = Sed_is_for_losers
override CC = c++
override CFLAGS = -std=c++98 -Wall -Wextra -Werror
override RM = rm -f

override define SRC
	main.cpp
	SedIsForLosers.cpp
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

NAME = fixed_point
override CC = c++
override CFLAGS = -std=c++98 -Wall -Wextra -Werror
override SRC = main.cpp Fixed.cpp
override OBJ = $(SRC:%.cpp=%.o)
override RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

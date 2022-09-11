NAME = Hi_This_Is_Brain
override CC = c++
override CFLAGS = -std=c++98 -Wall -Werror -Wextra
override SRC = main.cpp
override OBJ = main.o

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

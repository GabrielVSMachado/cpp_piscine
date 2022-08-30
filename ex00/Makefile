override NAME = megaphone
override CFLAGS = -std=c++98 -Wall -Wextra -Werror
override CC = c++

OBJ = megaphone.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) megaphone.o

fclean: clean
	$(RM) $(NAME)

re: clean all

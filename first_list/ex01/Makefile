override NAME = phonebook

override define SRC
	main.cpp
	Contact.cpp
	PhoneBook.cpp
	utils.cpp
endef


override CC = c++
override CFLAGS = -std=c++98 -Wall -Wextra -Werror

OBJ = $(SRC:%.cpp=%.o)

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

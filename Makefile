NAME = nooc

CPPFLAGS = -Wall -Wextra -Werror
CC = c++
CLEAR = rm -rf

SRC = src/main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
	$(CLEAR) $(OBJ)

fclean : clean
	$(CLEAR) $(NAME)

re : fclean all

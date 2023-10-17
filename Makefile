NAME = nooc
CPPFLAGS = -Wall -Wextra -Werror -I inc

SRC = src/nooc.cpp src/open.cpp src/scanner.cpp src/dns_resolve.cpp src/init.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

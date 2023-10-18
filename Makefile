NAME = nooc
CPPFLAGS = -Wall -Wextra -Werror -I inc

SRC = nooc.cpp open.cpp scanner.cpp dns.cpp init.cpp ports.cpp
OBJ = $(addprefix src/,$(SRC:.cpp=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	@c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all


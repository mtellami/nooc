NAME = nooc

CPPFLAGS = -Wall -Wextra -Werror -I $(INC)
CC = c++
CLEAR = rm -rf

INC = inc
SRC = src/nooc.cpp \
	src/open.cpp \
	src/scanner.cpp \
	src/dns_resolve.cpp

OBJ = $(SRC:.cpp=.o)

.o: .cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
	$(CLEAR) $(OBJ)

fclean : clean
	$(CLEAR) $(NAME)

re : fclean all

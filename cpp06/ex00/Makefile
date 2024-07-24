
NAME = convert

SRC = main.cpp ScalarConverter.cpp

CC = c++
RM = rm -f

FLAGS = -Wall -Wextra -Werror -std=c++98
DEPFLAGS = -MMD -MP

OBJ = $(SRC:.cpp=.o)
DEPS = $(SRC:.cpp=.d)

%.o: %.cpp Makefile
	$(CC) $(FLAGS) $(DEPFLAGS) -c $< -o $@

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) *.o *.d

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
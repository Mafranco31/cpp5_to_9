
NAME = game

SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

CC = c++
RM = rm -f

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)
DEPS = $(SRC:.cpp=.d)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) *.o *.d
	$(RM) *shrubbery

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
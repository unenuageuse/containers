# Variables

NAME		=	Containers
CC			=	c++
CFLAGS	=	
#-Werror -Wall -Wextra -std=c++98
SRCS		=	src/main.cpp
OBJ			=	$(SRCS:.c=.o)

# Rules

all: $(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiling $(NAME) done"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
	@echo "! Removed $(NAME)"

test: $(NAME)
	./$(NAME)

vtest: $(NAME)
	valgrind ./$(NAME)

re: fclean all

.PHONY: all clean fclean re test vtest

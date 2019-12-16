RM			= rm -rf
CC			= gcc
CFLAGS		= $(shell pkg-config --cflags criterion) --coverage -W -Wall -Wextra
LDFLAGS		= $(shell pkg-config --libs criterion) --coverage
SRC			= $(wildcard *.c)
OBJ			= $(SRC:.c=.o)
NAME		= ./tests

all: $(NAME)
	$(NAME); gcovr --exclude .*_tests.c

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ:.o=.gcda)

fclean: clean
	$(RM) $(NAME)

re: fclean all
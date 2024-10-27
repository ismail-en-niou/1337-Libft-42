NAME = libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)
ODIR = bin/
OBJ = $(addprefix $(ODIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $?
	ar rc $(NAME) $(OBJ)

$(ODIR)%.o: %.c
	mkdir -p $(ODIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(ODIR)*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
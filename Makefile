NAME = libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = ft_bzero.c ft_isdigit.c  ft_memmove.c ft_putstr_fd.c ft_strjoin.c \
      ft_strncmp.c ft_tolower.c ft_calloc.c ft_isprint.c ft_memset.c \
      ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c ft_isalnum.c ft_itoa.c ft_memchr.c \
      ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_isalpha.c \
      ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c ft_atoi.c ft_isascii.c \
      ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c

BONUS_SRC = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
            ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
            ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

BONUS_FLAG = .bonus

all: $(NAME)

bonus: $(BONUS_FLAG)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(BONUS_FLAG): $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)
	@touch $(BONUS_FLAG)

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o $(BONUS_FLAG)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

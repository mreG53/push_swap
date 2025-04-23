NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
SRC		= main.c parser.c validate.c ft_atol.c \
		push.c rotate.c reverse_rotate.c swap.c \
		sort.c sort_utils.c sort_small.c sort_hundred.c \
		ft_split.c sort_five_hundred.c free.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
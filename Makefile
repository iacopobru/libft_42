MAKEFLAGS += --no-print-directory
COMPPILER = cc
FLAG = -Wall -Wextra -Werror -std=c99
SRC = $(wildcard ft_*.c)
OBJ = $(SRC:.c=.o)
NAME = libft.a

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@make clean

all: $(NAME)

%.o: %.c
	@$(COMPPILER) $(FLAG) -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

prova: $(NAME)
	@make -C test_libft/ all
	@gcc $(FLAG) -std=gnu11 PROVE.c test_libft.a $(NAME) -o PROVE
	./PROVE

.PHONY: all clean fclean re prova
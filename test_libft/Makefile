MAKEFLAGS += --no-print-directory
COMPPILER = gcc
FLAG = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
NAME = test_libft.a

$(NAME): $(OBJ)
	@ar -rc ../$(NAME) $(OBJ)
	@ranlib ../$(NAME)
	@make clean

all: $(NAME)

%.o: %.c
	@$(COMPPILER) $(FLAG) -std=gnu11 -c $< -I..

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf ../$(NAME)

re: fclean all

r_def:
	bash rigth_def.sh

.PHONY: all clean fclean re prova
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ	= filler.o parser.o weight.o more_function.o
NAME = filler

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c 
	gcc -Wall -Wextra -Werror -c  $< -o $@ -I $(LIBFT_DIR) 

$(NAME): $(OBJ) $(LIBFT)
	gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

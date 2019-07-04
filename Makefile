
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJ	= 
NAME = libftfiller.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c 
	gcc -Wall -Wextra -Werror -c  $< -o $@ -I $(LIBFT_DIR) 

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) ./$(NAME)
	ar rc $(NAME) $(OBJ) $(LIBFT)
	ranlib $(NAME)
#	gcc $(OBJ) $(LIBFT) -o $(NAME)

main: $(NAME)
	gcc main.c $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

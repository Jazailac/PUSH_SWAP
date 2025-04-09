CC = cc
NAME = push_swap
FLAGS = -Wall -Wextra -Werror

src = main.c \
		init.c \
		parsing.c \
		push.c \
		utils.c \
		swap.c \
		rotate.c \
		rev_rotate.c \
		sort_small.c \
		sort_large.c \
		help_norm1.c \
		help_norm2.c

OBJ = $(src:.c=.o)
LIBFT_DIR = LIBFT
LIBFT = $(LIBFT_DIR)/libft.a  

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)  
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean: 
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean 

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re:
	make fclean
	make all

.PHONY: all clean fclean re

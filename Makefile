CC = cc
NAME = push_swap
FLAGS = -Wall -Wextra -Werror

src = srcs/main.c \
		srcs/init.c \
		srcs/parsing.c \
		srcs/push.c \
		srcs/utils.c \
		srcs/swap.c \
		srcs/rotate.c \
		srcs/rev_rotate.c \
		srcs/sort_small.c \
		srcs/sort_large.c \
		srcs/help_norm1.c \
		srcs/help_norm2.c \
		srcs/help_norm3.c 


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

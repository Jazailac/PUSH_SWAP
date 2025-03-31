NAME = push_swap

CFlAGS = -Wall -Wextra -Werror 
CC = cc 

SRC = src/main.c src/validate_input.c src/stack.c src/operations.c
OBJS = $(SRC:.c=.o)

LIBFT_DIR = LIBFT
LIBFT = $(LIBFT_DIR)/libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean : 
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS) 

fclean : clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all re fclean clean 
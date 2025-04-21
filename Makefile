CC = cc
NAME = push_swap
FLAGS = -Wall -Wextra -Werror

# ANSI color codes
GREEN = \033[0;32m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

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
	@echo "$(BLUE)▌$(RESET) $(CYAN)Compiling $(YELLOW)$<$(RESET) $(BLUE)→$(RESET) $(PURPLE)$@$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "$(CYAN)"
	@echo "██████╗ ██╗   ██╗███████╗██╗  ██╗    ███████╗██╗    ██╗ █████╗ ██████╗ "
	@echo "██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔════╝██║    ██║██╔══██╗██╔══██╗"
	@echo "██████╔╝██║   ██║███████╗███████║    ███████╗██║ █╗ ██║███████║██████╔╝"
	@echo "██╔═══╝ ██║   ██║╚════██║██╔══██║    ╚════██║██║███╗██║██╔══██║██╔═══╝ "
	@echo "██║     ╚██████╔╝███████║██║  ██║    ███████║╚███╔███╔╝██║  ██║██║     "
	@echo "╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝    ╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     "
	@echo "$(RESET)"
	@echo "$(YELLOW)"
	@echo "         [5]        |A|        "
	@echo "         [4]        |B|        "
	@echo "    +--> [3]        |C|        "
	@echo "    |    [2]        |D|        "
	@echo "  PUSH   [1]        |E|        "
	@echo "    |    [0]        |F|        "
	@echo "    v    ---        ---        "
	@echo "         STACK A    STACK B    "
	@echo "     ------------>SWAP<---------"
	@echo "$(RESET)"
	@echo "$(CYAN)╔════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)║  $(GREEN)Building push_swap...                             $(CYAN) ║$(RESET)"
	@echo "$(CYAN)╚════════════════════════════════════════════════════════╝$(RESET)"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(GREEN)╔════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║  🎮 push_swap is ready to sort!                         $(GREEN)║$(RESET)"
	@echo "$(GREEN)╚════════════════════════════════════════════════════════╝$(RESET)"

$(LIBFT):
	@echo "$(PURPLE)╔════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(PURPLE)║  $(BLUE)Compiling libft library...                         $(PURPLE) ║$(RESET)"
	@echo "$(PURPLE)╚════════════════════════════════════════════════════════╝$(RESET)"
	@make -C $(LIBFT_DIR)

clean: 
	@echo "$(YELLOW)╔════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(YELLOW)║  Cleaning object files...                              $(YELLOW)║$(RESET)"
	@echo "$(YELLOW)╚════════════════════════════════════════════════════════╝$(RESET)"
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean 

fclean:
	@echo "$(RED)╔════════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(RED)║  Full cleanup in progress...                           $(RED)║$(RESET)"
	@echo "$(RED)╚════════════════════════════════════════════════════════╝$(RESET)"
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)All clean! ✨$(RESET)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re

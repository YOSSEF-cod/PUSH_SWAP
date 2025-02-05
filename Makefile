NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =	src/push_swap.c src/add_node_back.c src/split_argiment.c src/push_swap_utlis.c \
		src/rules_swap.c src/rules_push.c src/rules_rotate.c src/rules_reverse_rotate.c \
		src/sort_argement.c src/algorithem.c src/exit_and_free.c

SRCSB = bonus_src/push_swap_bonus.c bonus_src/add_node_back.c bonus_src/split_argiment.c \
		bonus_src/push_swap_utlis.c bonus_src/rules_swap.c bonus_src/rules_push.c \
		bonus_src/rules_rotate.c bonus_src/rules_reverse_rotate.c bonus_src/exit_and_free.c \
		bonus_src/get_next_line.c bonus_src/checker_bonus.c 

OBJB = $(SRCSB:.c=.o)
OBJ = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME_BONUS) : $(OBJB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJB) $(LIBFT) -o $(NAME_BONUS)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJB)
	$(MAKE) -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
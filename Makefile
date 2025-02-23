SRC =	push_swap.c push_swap_simple_sort.c push_swap_sort_handler.c \
	push_swap_stack.c push_swap_stack2.c push_swap_stack_r_instructions.c \
	push_swap_stack_instructions.c push_swap_stack_p_instructions.c \
	push_swap_stack_rr_instructions.c \
	push_swap_binary_radix.c \
	push_swap_bubble_sort.c \
	push_swap_shaker_sort.c \
	push_swap_double_bubble_sort.c \
	push_swap_optimized_bubble.c \
	push_swap_optimized_shaker_sort.c \
	push_swap_insertion_sort.c \
	push_swap_optimized_insertion.c \
	push_swap_selection_sort.c \
	push_swap_quick_sort.c \
	push_swap_optimized_quick_sort.c \
	push_swap_comb_sort.c \
	push_swap_double_shaker_sort.c \
	push_swap_optimized_double_shaker_sort.c \
	push_swap_stalin_sort.c \
	push_swap_largest_stalin_sort.c \
	push_swap_recursive_stalin_sort.c \
	push_swap_bogo_sort.c \

NAME = push_swap
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
RM			= rm -rf
CC			= cc
AR			= ar -crs
FLAGS		= -Wall -Wextra -Werror
LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -I$(LIBFT_PATH) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I$(LIBFT_PATH) -L$(LIBFT_PATH) -lft

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

re: fclean all

bonus: all

clean:
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

fclean: clean
	make -C $(LIBFT_PATH) fclean

.PHONY: all clean fclean re bonus


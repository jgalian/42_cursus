CHECKER_NAME = checker
PUSH_SWAP_NAME = push_swap
CC = gcc
FLAGS = -Wall -Wextra -g
INC = -Iincludes/ -I$(LIB_DIR)

CHECKER_SRCS =	ch_checker.c ch_operations.c co_operations.c\
				co_set_initial_stack.c co_utils.c \
				co_list_management.c \
				co_list_management_locate_value.c \
				co_list_management_print.c \
				co_list_management_locate_value_2.c \
				co_list_management_values_calculations.c
CHECKER_OBJS =	$(CHECKER_SRCS:.c=.o)
CHECKER_OBJ = $(addprefix $(OBJ_DIR),$(CHECKER_OBJS))

PUSH_SWAP_SRCS =	ps_push_swap.c ps_quick_sort.c ps_insertion_sort.c \
					co_operations.c co_list_management.c \
					co_list_management_locate_value.c \
					co_list_management_print.c \
					co_list_management_locate_value_2.c \
					co_list_management_values_calculations.c \
					ps_operation_reverse_rotate.c ps_operation_push.c \
					ps_operation_rotate.c ps_operation_swap.c \
					co_set_initial_stack.c co_utils.c
PUSH_SWAP_OBJS =	$(PUSH_SWAP_SRCS:.c=.o)
PUSH_SWAP_OBJ = $(addprefix $(OBJ_DIR),$(PUSH_SWAP_OBJS))

LIB_DIR = libft/
SRC_DIR = srcs/
OBJ_DIR = objs/

all: $(CHECKER_NAME) $(PUSH_SWAP_NAME)

$(CHECKER_NAME): $(CHECKER_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(CHECKER_NAME) $(CHECKER_OBJ) -L $(LIB_DIR) -lft
	@echo "##### checker compiling finished! #####"

$(PUSH_SWAP_NAME): $(PUSH_SWAP_OBJ)
	@make -C $(LIB_DIR) --silent
	@gcc -o $(PUSH_SWAP_NAME) $(PUSH_SWAP_OBJ) -L $(LIB_DIR) -lft
	@echo "##### push_swap compiling finished! #####"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "##### Creating" [ $@ ] " #####"
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean:
	@make -C $(LIB_DIR) clean  --silent
	@rm -f $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	@echo "##### Removed object files #####"

fclean: clean
	@make -C $(LIB_DIR) fclean  --silent
	@rm -f $(CHECKER_NAME) $(PUSH_SWAP_NAME)
	@echo "##### Removed binary files #####"

re: fclean all

.PHONY: all clean fclean re

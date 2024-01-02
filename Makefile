NAME				= push_swap
LIBFT				= ./libft/Libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/
CC					= cc
CFLAGS				= -Wall -Wextra -Werror -I
RM					= rm -f
COLOUR_END		=	\033[0m
COLOUR_GREEN	=	\033[0;32m
COLOUR_RED		=	\033[0;31m

COMMANDS_DIR		=	$(SRC_DIR)instructions/push.c \
						$(SRC_DIR)instructions/reverse_rotate.c \
						$(SRC_DIR)instructions/rotate.c \
						$(SRC_DIR)instructions/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap.c \
						$(SRC_DIR)checks.c \
						$(SRC_DIR)utils.c \
						$(SRC_DIR)b_set_target.c \
						$(SRC_DIR)a_set_target.c \
						$(SRC_DIR)sort.c \
						$(SRC_DIR)sort_three.c \
						$(SRC_DIR)init_stack.c \


SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:				
					make all

$(LIBFT):
					make -C ./libft

all: 				$(NAME)

$(NAME): 			$(LIBFT) $(OBJ)
					$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)
					@echo "$(COLOUR_GREEN)[PUSH_SWAP] Push_swap Created !$(COLOUR_END)"

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c inc/push_swap.h
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft
					@echo "$(COLOUR_RED)[PUSH_SWAP] Push_swap Object Files Deleted !$(COLOUR_END)"

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)
					@make fclean -C ./libft
					@echo "$(COLOUR_RED)[PUSH_SWAP] Push_swap Deleted !$(COLOUR_END)"

re: 				fclean all

.PHONY: 			start all clean fclean re
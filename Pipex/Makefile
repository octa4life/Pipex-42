NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f

SRC_DIR	= src
OBJ_DIR	= objs
INC_DIR	= includes

# Sources
_SRCS = pipex.c pipex_parsing.c pipex_utils.c
SRCS = $(addprefix $(SRC_DIR)/, $(_SRCS))

# Objets
_OBJS = $(_SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(_OBJS))

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/gnl/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re:	fclean all

bonus: re

test: all
	./$(NAME)
.PHONY:	all clean fclean re bonus test

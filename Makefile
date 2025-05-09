NAME = so_long

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -Ilibft -Iget_next_line

SRCS = main.c init.c parser.c draw_map.c map_check.c close.c wall_check.c floodfill.c \
       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c move.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) \
		-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd \
		-o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

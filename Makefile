

NAME = so_long

CC = gcc

DEBUG = -fsanitize=address

CFLAGS = -Wall -Wextra -Werror

SRCS = so_long.h\
		main.c

OBJS = $(SRCS:.c=.o)

RM = rm -f


all: $(NAME)

$(NAME): $(OBJS)
	@make -C minilibx-linux/
	@make -C libft/
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a minilibx-linux/libmlx_Linux.a -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "so_long" compiled!\n"

debug: $(OBJS)
	@make -C minilibx-linux/
	@make -C libft/
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJS) libft/libft.a minilibx-linux/libmlx_Linux.a -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "so_long compiled with debug!\n"

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include -Imlx -O3 -c $< -o $@


clean:
	@make clean -C libft/
	@$(RM) $(OBJS)

fclean: clean
	@make clean -C minilibx-linux/
	@make fclean -C libft/
	@$(RM) $(NAME)

done:
	@echo "$$HEADER"

re: fclean all

.PHONY: all clean fclean re
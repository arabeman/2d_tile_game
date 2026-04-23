NAME = so_long
MAIN = ./main.c
SRCS = $(MAIN) \
		./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		./ft_map/ft_map_invalid.c ./ft_map/ft_map.c ./ft_map/ft_change_char.c \
		./ft_map/ft_count_collectible.c \
		./ft_map/ft_no_exit.c ./ft_map/ft_copy_map.c  ./ft_map/ft_plus_fill.c \
		./ft_map/ft_find.c ./ft_game/ft_game.c ./ft_game/ft_asset.c \
		./ft_game/ft_hook.c ./ft_game/ft_render.c ./ft_game/ft_move_player.c 

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./ft_printf/libftprintf.a
LIBMLX = ./mlx-linux/libmlx.a

all: $(NAME)

$(LIBMLX):
	git clone https://github.com/42Paris/minilibx-linux.git mlx-linux
	cd mlx-linux && ./configure && cd ..

%.o: %.c $(LIBMLX)
	gcc -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
	cd ft_printf/ && make && cd ..

$(NAME): $(OBJS) $(LIBFT)
	gcc $(OBJS) $(LIBMLX) $(LIBFT) -Lmlx -L/usr/lib/X11 -lXext -lX11 -o $(NAME)

clean:
	rm -f $(OBJS) && rm -f $(MAIN:.c=.o)
	cd ft_printf/ && make clean && cd ../libft/ && make clean

fclean: clean
	rm -f $(NAME)
	rm -rf mlx-linux
	cd ft_printf/ && make fclean && cd ..
	cd libft/ && make fclean && cd ..

re: fclean all

.PHONY: all clean fclean re


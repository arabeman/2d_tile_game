SRCS = ft_printf.c \
	./ft_conversions/ft_basic_conversions.c \
	./ft_print/ft_print_char.c \
	./ft_print/ft_print_hex_lower.c \
	./ft_print/ft_print_hex_upper.c \
	./ft_print/ft_print_int.c \
	./ft_print/ft_print_percent.c \
	./ft_print/ft_print_pointer.c \
	./ft_print/ft_print_string.c \
	./ft_print/ft_print_unsigned_int.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
LIBFT = ../libft/libft.a
NAME	= libftprintf.a

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(LIBFT):
	cd ../libft/ && make && cd ../ft_printf

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) && cd ../libft/ && make fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

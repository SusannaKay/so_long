NAME = so_long
CFLAGS = -Wall -Wextra -Werror


MINILIBX_PATH = ./mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

GNL_PATH = ./get_next_line

PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a


SRC = main.c get_next_line_bonus.c get_next_line_utils_bonus.c get_map.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MINILIBX) $(PRINTF)
	gcc $(OBJ) $(CFLAGS) $(PRINTF) $(MINILIBX) mlx/libmlx.a -L./mlx -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(PRINTF)

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(MINILIBX):
	chmod 777 $(MINILIBX_PATH)/configure
	make -C $(MINILIBX_PATH)
$(PRINTF) :
	make -C $(PRINTF_PATH)
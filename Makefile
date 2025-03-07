NAME = so_long
CFLAGS = -gdwarf-4 -O0 -I./include -Imlx -fsanitize=address


MINILIBX_PATH = ./mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = main.c get_map.c check_map.c flood_fill.c init_struct.c exit_game.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ) $(MINILIBX) $(LIBFT)
	gcc $(OBJ) $(CFLAGS) $(LIBFT) $(MINILIBX) mlx/libmlx.a -L./mlx -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
	
clean:
	rm -f $(OBJ)
	make -C $(MINILIBX_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(MINILIBX_PATH) fclean
	make -C $(LIBFT_PATH) fclean

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -I/usr/include -Imlx -I$(LIBFT_PATH) -O3 -c $< -o $@

$(MINILIBX):
	chmod 777 $(MINILIBX_PATH)/configure
	make -C $(MINILIBX_PATH)

$(LIBFT) :
	make -C $(LIBFT_PATH)

.PHONY : all bonus clean fclean re
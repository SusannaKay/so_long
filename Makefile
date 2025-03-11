NAME = so_long
NAME_BONUS = so_long_bonus
CFLAGS = -g -gdwarf-4 -O0 -I./include -Imlx


MINILIBX_PATH = ./mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC =	src/main.c src/get_map.c src/check_map.c src/init_struct.c src/exit_game.c src/flood_fill.c src/graphics.c src/move_player.c
SRC_BONUS = bonus/main.c bonus/get_map.c bonus/check_map.c bonus/init_struct.c bonus/exit_game.c bonus/flood_fill.c bonus/graphics.c bonus/move_player.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS: .c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MINILIBX) $(LIBFT)
	gcc $(OBJ) $(CFLAGS) $(LIBFT) $(MINILIBX) mlx/libmlx.a -L./mlx -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

bonus:
$(NAME_BONUS) = $(OBJ_BONUS) $(MINILIBX) $(LIBFT)
	gcc $(OBJ_BONUS) $(CFLAGS) $(LIBFT) $(MINILIBX) mlx/libmlx.a -L./mlx -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME_BONUS)

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
NAME = so_long
NAME_BONUS = so_long_bonus
CFLAGS = -g -gdwarf-4 -O0 -I./include -Imlx

MINILIBX_PATH = ./mlx
MINILIBX = $(MINILIBX_PATH)/libmlx.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = src/main.c src/get_map.c src/check_map.c src/init_struct.c src/exit_game.c src/flood_fill.c src/graphics.c src/move_player.c
SRC_BONUS = bonus/bonus_main.c bonus/bonus_get_map.c bonus/bonus_check_map.c bonus/bonus_init_struct.c bonus/bonus_exit_game.c bonus/bonus_flood_fill.c bonus/bonus_graphics.c bonus/bonus_move_player.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)
	@echo -e "\033[34m"
	@echo "  _____   ____    _       ____    ____   _   __   ____  "
	@echo " / ___/  / __ \  | |     / __ \  / __ \ | | / /  / __ \ "
	@echo " \__ \  / / / /  | |    / / / / / / / / | |/ /  / / / / "
	@echo "___/ / / /_/ /   | |___/ /_/ / / /_/ /  |   /  / /_/ /  "
	@echo "/____/  \____/   |_____/_____/  \____/  /_/|_|  \____/  "
	@echo -e "\033[0m"

$(NAME): $(OBJ) $(MINILIBX) $(LIBFT)
	gcc $(OBJ) $(CFLAGS) $(LIBFT) $(MINILIBX) mlx/libmlx.a -L./mlx -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(MINILIBX) $(LIBFT)
	gcc $(OBJ_BONUS) $(CFLAGS) $(LIBFT) $(MINILIBX) mlx/libmlx.a -L./mlx -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make -C $(MINILIBX_PATH) clean
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make -C $(MINILIBX_PATH) fclean
	make -C $(LIBFT_PATH) fclean

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -I/usr/include -Imlx -I$(LIBFT_PATH) -O3 -c $< -o $@

bonus/%.o: bonus/%.c
	gcc $(CFLAGS) -I/usr/include -Imlx -I$(LIBFT_PATH) -O3 -c $< -o $@

$(MINILIBX):
	chmod 777 $(MINILIBX_PATH)/configure
	make -C $(MINILIBX_PATH)

$(LIBFT):
	make -C $(LIBFT_PATH)

.PHONY: all bonus clean fclean re
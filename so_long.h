#ifndef SO_LONG_H
#define SO_LONG_H

#include "./mlx/mlx.h"
#include "./libft/libft.h"

#include <X11/keysym.h>
#include <X11/X.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define TILESIZE 64
#define UP 25
#define DOWN 39
#define LEFT 38
#define RIGHT 40

typedef struct s_map
{
    char *filename;
    char **map;
    void *mlx;
    void *win;
    struct s_graphics *graphics;
    int len_row;
    int rows;
    int collect;
    int p_x;
    int p_y;
    int moves;
    int score;
} t_map;

typedef struct s_graphics
{
    void *player;
    void *floor;
    void *wall;
    void *exit;
    void *collect;
} t_graphics;

int verify_map(t_map *map);
void read_map(t_map *map);
t_map *create_tmap(t_map *map);
t_graphics *create_tgraphics(t_graphics *graphics);
int exit_game(t_map *map, const char *error_message);
int flood_fill(t_map *map);
void render_map(t_map *map);
#endif

//valgrind -s --leak-check=full --show-leak-kinds=all
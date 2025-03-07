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

typedef struct s_map
{
    char *filename;
    char **map;
    void *mlx;
    void *win;
    int len_row;
    int rows;
    int collect;
    int p_x;
    int p_y;
    int moves;
    int score;
} t_map;

int verify_map(t_map *map);
void read_map(t_map *map);
t_map *create_tmap(t_map *map);
void exit_game(t_map *map, const char *error_message);
#endif
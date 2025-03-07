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

typedef struct s_mlx
{
    void *mlx;
    void *win;
} t_mlx;

typedef struct s_player
{
    int x;
    int y;
    int moves;
    int score;
} t_player;

typedef struct s_map
{
    char *filename;
    char **map;
    int len_row;
    int rows;
    int collect;
    void *mlx;
    void *win;
} t_map;

int verify_map(t_map *map);
void read_map(t_map *map);
t_map *create_tmap(void);
t_player *create_tplayer(void);
void exit_game(t_map *map, t_player *player, const char *error_message);
#endif
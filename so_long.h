#ifndef SO_LONG_H
# define SO_LONG_H

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
    void    *mlx;
    void    *win;
}   t_mlx;

typedef struct s_player
{
    int x;
    int y;
    int moves;
    int score;
}   t_player;

typedef struct s_map 
{
    char    *filename;
    char **map;
    int  len_row;  
    int  rows; 
    int  collect;
}   t_map;

#endif
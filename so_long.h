#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include "funct/libft/ft_printf/ft_printf.h"
#include "funct/libft/libft.h"

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
    int  width;
    int  height;
    int  collect;
}   t_map;

void find_player(char **map);

#endif
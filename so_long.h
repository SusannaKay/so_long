#ifndef SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stddef.h>
#include <stdlib.h>
#include "./get_next_line_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./ft_printf/ft_printf.h"

typedef struct s_data
{
    void    *mlx;
    void    *win;
    void    *img;
    char    **map;
}   t_data;

int read_ber(t_data data);

#endif
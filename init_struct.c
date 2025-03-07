#include "so_long.h"

static void init_map(t_map *map)
{
    map->filename = NULL;
    map->map = NULL;
    map->mlx = NULL;
    map->win = NULL;
    map->len_row = 0;
    map->rows = 0;
    map->collect = 0;
    map->moves = 0;
    map->score = 0;
    map->p_x = 0;
    map->p_y = 0;
}

t_map *create_tmap(t_map *map)
{
    
    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    init_map(map);
    return (map);
}
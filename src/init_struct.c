#include "so_long.h"

static void init_map(t_map *map)
{
    map->filename = NULL;
    map->map = NULL;
    map->mlx = NULL;
    map->win = NULL;
    map->graphics = NULL;
    map->len_row = 0;
    map->rows = 0;
    map->collect = 0;
    map->moves = 0;
    map->score = 0;
    map->p_x = 0;
    map->p_y = 0;
}
static void init_graphcs(t_graphics *graphics)
{
    graphics->collect = NULL;
    graphics->player = NULL;
    graphics->floor = NULL;
    graphics->wall = NULL;
    graphics->exit = NULL;
}
t_map *create_tmap(t_map *map)
{

    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    init_map(map);
    return (map);
}
t_graphics *create_tgraphics(t_graphics *graphics)
{
    graphics = malloc(sizeof(t_graphics));
    if (!graphics)
        return (NULL);
    init_graphics(graphics);
    return (graphics);
}
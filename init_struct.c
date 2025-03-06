#include "so_long.h"

static void init_map(t_map *map)
{
    map->filename = NULL;
    map->map = NULL;
    map->len_row = 0;
    map->rows = 0;
    map->collect = 0;
}
static void init_player(t_player *player)
{
    player->moves = 0;
    player->score = 0;
    player->x = 0;
    player->y = 0;
}
static void init_window(t_mlx *data)
{
    data->mlx = NULL;
    data->win = NULL;
}
int create_struct()
{
    
}
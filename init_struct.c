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

t_map *create_tmap(void)
{
    t_map *map;
    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    init_map(map);
    return (map);
}
t_player *create_tplayer(void);
{
    t_player *player;
    player = malloc(sizeof(t_player));
    if (!player)
        return (NULL);
    init_player(map);
    return (player);
}
#include "bonus_so_long.h"



int enemy_patrol(t_map *map)
{
    int next_x;
    
    if ( map-> enemy->frame_delay++ < 20)
        return(0);
    map->enemy->frame_delay = 0;
    next_x = map->enemy->x + map->enemy->direction;
    if (map->map[map->enemy->y][next_x] == '1' || map->map[map->enemy->y][next_x] == 'E' || map->map[map->enemy->y][next_x] == 'A' || map->map[map->enemy->y][next_x] == 'C') 
        map->enemy->direction *= -1; 
    else
    {
        if(map->map[map->enemy->y][next_x] == 'P')
            return (exit_game(map, "You Loose!\n"), 0);
        if(map->map[map->enemy->y][next_x] != 'C')
        {map->map[map->enemy->y][map->enemy->x] = '0'; 
        map->enemy->x = next_x;                      
        map->map[map->enemy->y][map->enemy->x] = 'A'; }
    }
    return (0);
}
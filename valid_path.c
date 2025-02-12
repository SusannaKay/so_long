#include "so_long.h"

void find_player(char **map)
{
    int x;
    int y;
    t_player player;

    y = 0;
    x = 0;
    while(map[y] != NULL)
    {
        while(map[y][x] != '\0')
        {
            if (map[y][x] == 'P')
            {
                player.x = x;
                player.y = y;
            }
            x++;
        }
        y++;
    }
}


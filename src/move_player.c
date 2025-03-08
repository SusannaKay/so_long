#include "so_long.h"

int move_player(int keysym, t_map *map)
{
    if (keysym == e)
        exit_game(map, "Quit program");
    return (0);
}
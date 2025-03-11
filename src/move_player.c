#include "../so_long.h"

int move_player(int keysym, t_map *map)
{
    int new_x;
    int new_y;

    new_x = map->p_x;
    new_y = map->p_y;
    if (keysym == UP)
        new_y -= 1;
    if (keysym == DOWN)
        new_y += 1;
    if (keysym == LEFT)
        new_x -= 1;
    if (keysym == RIGHT)
        new_x += 1;
    if (map->map[new_y][new_x] == 'E' && map->score == map->collect)
            return (exit_game(map, "You win!\n"), 0);
    else if (map->map[new_y][new_x] == 'E' && map->score != map->collect)
        ft_printf("You must collect all the cookies!\n");
    if (map->map[new_y][new_x] != '1' && map->map[new_y][new_x] != 'E')  
    {
        map->map[map->p_y][map->p_x] = '0';
        if (map->map[new_y][new_x] == 'C')
            map->score++;
    map->map[new_y][new_x] = 'P';
    map->moves++;
    ft_printf("Moves number: %d\n", map->moves);
    map->p_x = new_x;
    map->p_y = new_y;
    return(render_map(map, 1),0);
    }
    return (1);
}

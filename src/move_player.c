#include "../so_long.h"

int move_player(int keycode, t_map *map)
{
    int new_x;
    int new_y;

    new_x = map->p_x;
    new_y = map->p_y;
    if (keycode == UP)
        new_x -= 1;
    if (keycode == DOWN)
        new_x += 1;
    if (keycode == LEFT)
        new_y -= 1;
    if (keycode == RIGHT)
        new_y += 1;
    if (map->map[new_y][new_x] == '1')
        return (1);
    map->map[map->p_y][map->p_x] = '0';
    if (map->map[new_y][new_x] == 'C')
        map->score++;
    if (map->map[new_y][new_x] == 'E' && map->score == map->collect)
        return (exit_game(map, "You win!\n"), 0);
    map->map[new_y][new_x] = 'P';
    map->moves++;
    ft_printf("moves number: %d", map->moves);
    map->p_x = new_x;
    map->p_y = new_y;
    render_map(map);
    return (1);
}
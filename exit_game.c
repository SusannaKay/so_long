#include "so_long.h"
#include <stdlib.h>

void free_map(t_map *map)
{
    int i;

    if (!map)
        return;
    if (map->map)
    {
        i = 0;
        while (map->map[i])
        {
            free(map->map[i]);
            i++;
        }
        free(map->map);
    }
    if (map->filename)
        free(map->filename);
    free(map);

    void free_player(t_player * player)
    {
        if (!player)
            return;
        free(player);
    }

    void exit_game(t_map * map, t_player * player, char *error_message)
    {
        if (error_message)
            ft_printf("Errore: %s\n", error_message);
        mlx_destroy_window(map->mlx, map->win);
        mlx_destroy_display(map->mlx);
        free(map->mlx);
        free_map(map);
        free_player(player);
        exit(EXIT_SUCCESS);
        return (0);
    }

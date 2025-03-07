#include "so_long.h"

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
    if (map->mlx)
        free(map->mlx);
    if (map->win)
        free(map->win);
    free(map);
}


void exit_game(t_map *map, const char *error_message)
{
        if (error_message)
            ft_printf("Errore: %s\n", error_message);
        mlx_destroy_window(map->mlx, map->win);
        mlx_destroy_display(map->mlx);
        free_map(map);
        exit(EXIT_SUCCESS);
        return;
}

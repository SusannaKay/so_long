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
            map->map[i] = NULL;
            i++;
        }
        free(map->map);
        map->map = NULL;
    }
    if (map->filename)
        {
            free(map->filename);
            map->filename = NULL;
        }
    free(map);
}


void exit_game(t_map *map, const char *error_message)
{
    if (error_message)
        ft_printf("Errore: %s\n", error_message);

    if (map)
    {
        
        if (map->mlx && map->win)
            mlx_destroy_window(map->mlx, map->win);

        if (map->mlx)
            mlx_destroy_display(map->mlx);
        free_map(map);
        
    }

    exit(EXIT_SUCCESS);
}
// {
//         if (error_message)
//             ft_printf("Errore: %s\n", error_message);
//         free_map(map);
//         mlx_destroy_window(map->mlx, map->win);
//         mlx_destroy_display(map->mlx);
        
//         exit(EXIT_SUCCESS);
//         return;
// }

#include "so_long.h"

static void free_map(t_map *map)
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
    if (map->graphics)
    {
        free(map->graphics);
        map->graphics = NULL;
    }
    free(map);
}

static void free_graphics(t_graphics *graphics)
{
    if (graphics->collect = NULL)
    {
        free(graphics->collect);
        graphics->collect = NULL;
    }
    if (graphics->player)
    {
        free(graphics->player);
        graphics->player = NULL;
    }
    if (graphics->floor)
    {
        free(graphics->floor);
        graphics->floor = NULL;
    }
    if (graphics->wall)
    {
        free(graphics->wall);
        graphics->wall = NULL;
    }
    if (graphics->exit)
    {
        free(graphics->exit);
        graphics->exit = NULL;
    }
}

int exit_game(t_map *map, const char *error_message)
{
    if (ft_strncmp(error_message, "!", ft_strlen(error_message)) == 0)
        error_message = NULL;
    if (error_message)
        ft_printf("Error: %s\n", error_message);

    if (map)
    {
        if (map->mlx && map->win)
            mlx_destroy_window(map->mlx, map->win);

        if (map->mlx)
            mlx_destroy_display(map->mlx);
        free_graphics(map->graphics);
        free_map(map);
    }
    exit(EXIT_SUCCESS);
    return (0);
}

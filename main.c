#include "so_long.h"
// TO DO: function to create and init structs
// TO DO: function to free the structs
// TO DO: add close function with mouse ( + check for seg fault )

static void create_window(t_map *map)
{
    map->mlx = mlx_init();
    if (!map->mlx)
    {
        free(map);
    }
    map->win = mlx_new_window(map->mlx, 1920, 1080, "So Long");
    if (!map->win)
    {
        free(map->mlx);
        free(map);
    }
}
static int close_win(int keysym, t_map *map)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(map->mlx, map->win);
        mlx_destroy_display(map->mlx);
    }
    free(map);
    exit(EXIT_SUCCESS);
}
static void create_loop(t_map *map)
{
    mlx_hook(map->win, KeyPress, KeyPressMask, close_win, map);
    mlx_mouse_hook(map->win, close_win, map);
    mlx_loop(map->mlx);
    free(map->mlx);
    free(map);
}
int main(int argc, char *argv[])
{
    t_map *map;

    if (argc == 2)
    {
        if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
            return (ft_printf("Error\n formato mappa non valido"), 1);

        map = malloc(sizeof(t_map));
        if (!map)
            return (0);

        map->filename = ft_strjoin("./", argv[1]);
        if (!map->filename)
        {
            ft_printf("libero map");
            free(map);
            return (0);
        }
        read_map(map);
        verify_map(map);
        create_window(data, map);
        create_loop(data);

        free(map->filename);
        free(map);
        return (0);
    }
    return (ft_printf("Error\n specificare una mappa"), 1);
}

#include "so_long.h"

static void create_window(t_mlx *data, t_map *map)
{
    data->mlx = mlx_init();
    if (!data->mlx)
    {
        free(data);
        free(map);
    }
    data->win = mlx_new_window(data->mlx, 1920, 1080, "So Long");
    if (!data->win)
    {
        free(data->mlx);
        free(data);
        free(map);
    }
}
static int close_win(int keysym, t_mlx *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx, data->win);
        mlx_destroy_display(data->mlx);
    }
    free(data);
    exit(EXIT_SUCCESS);
}
static void create_loop(t_mlx *data)
{
    mlx_hook(data->win, KeyPress, KeyPressMask, close_win, data);
    mlx_mouse_hook(data->win, close_win, data);
    mlx_loop(data->mlx);
    free(data->mlx);
    free(data);
}
int main(int argc, char *argv[])
{
    t_mlx *data;
    t_map *map;

    if (argc == 2)
    {
        if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
            return (ft_printf("Error\n formato mappa non valido"), 1);

        map = malloc(sizeof(t_map));
        if (!map)
            return (0);

        map->filename = ft_strjoin("maps/", argv[1]);
        if (!map->filename)
        {
            free(map);
            return (0);
        }

        data = malloc(sizeof(t_mlx));
        if (!data)
        {
            free(map->filename);
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
    return (1);
}

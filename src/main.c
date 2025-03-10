#include "../so_long.h"

static void create_window(t_map *map)
{
    map->mlx = mlx_init();
    if (!map->mlx)
        free(map);
    map->win = mlx_new_window(map->mlx, (TILESIZE * map->len_row), (TILESIZE * map->rows), "So Long");
    if (!map->win)
        exit_game(map, "Finestra non creata");
}
static int close_win(int keysym, t_map *map)
{
    if (keysym == XK_Escape)
        exit_game(map, "Quit program");
    return (0);
}
static void create_loop(t_map *map)
{
    //mlx_hook(map->win, KeyPress, KeyPressMask, move_player, map);
    mlx_hook(map->win, KeyPress, KeyPressMask, close_win, map);
    mlx_hook(map->win, 17, 0L, exit_game, map);
    mlx_loop(map->mlx);
}
int main(int argc, char *argv[])
{
    t_map *map;
    t_graphics *graphics;

    if (argc == 2)
    {
        if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
            return (ft_printf("Error\n formato mappa non valido"), 1);

        map = create_tmap(map);
        map->filename = ft_strjoin("maps/", argv[1]);
        if (!map->filename)
            exit_game(map, "Filename non trovato");
        read_map(map);
        verify_map(map);
        graphics = create_tgraphics(graphics);
        map->graphics = graphics;
        if(!map->graphics)
            {ft_printf("graphics e' null");
            return(0);}
        create_window(map);
        render_map(map);
        create_loop(map);
        return (0);
    }
    return (ft_printf("Error\n specificare una mappa"), 1);
}

#include "so_long.h"

static int close_win(int keysym, t_mlx *data)
{
    if(keysym == XK_Escape)
        {
            mlx_destroy_window(data->mlx, data->win);
            mlx_destroy_display(data->mlx);
        }
    free(data->mlx);
    exit (EXIT_SUCCESS);
}

int     main(int argc, char *argv[])
{
    t_mlx  *data;
    t_map  *map;
 
    if(argc == 2)
    {
        data = malloc(sizeof(t_mlx));
        if(!data)
            return(1);
        map = malloc(sizeof(t_map));
        if (!map)
        {free(data);
            return(1);}
        data->mlx = mlx_init();
    if (!data->mlx)
    {
        free(data);
        free(map);
        return (1);
    }
    data->win = mlx_new_window(data->mlx, 1920, 1080, "So Long");
    if (!data->win)
        {
            free(data->mlx);
            free(data);
            free(map);
            return(1);
            }
    map->filename = ft_strjoin("./", argv[1]);
    read_map(map);
    
    mlx_hook(data->win, KeyPress, KeyPressMask, close_win, &data);
    mlx_mouse_hook(data->win, close_win, &data);
    mlx_loop(data->mlx);
    free(data->mlx);
    free(data);
    free(map);
    return (0);
    }
    return(ft_printf("Error\n specificare una mappa"), 1);
}
    //data.img = mlx_xpm_file_to_image(data.mlx, img_path, &size, &size);
    //if (!data.img)
   //     return (0);
    //read_ber(data);

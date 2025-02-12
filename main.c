#include "so_long.h"

static int close_win(int keysym, t_mlx data)
{
    if(keysym == XK_Escape)
        {
            mlx_destroy_window(data.mlx, data.win);
            mlx_destroy_display(data.mlx);
        }
    free(data.win);
    return (0);
}

int     main(int argc, char *argv[])
{
    t_mlx  data;
    t_map  map;
 
    if(argc == 2)
    {
        data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    data.win = mlx_new_window(data.mlx, 1920, 1080, "So Long");
    if (!data.win)
        return(free(data.mlx), 1);
    map.filename = ft_strjoin("./", argv[1]);
    ft_printf("%s", map.filename);
    mlx_hook(data.win, KeyPress, KeyPressMask, close_win, &data);
    mlx_mouse_hook(data.win, close_win, &data);
    mlx_loop(data.mlx);
    return (0);
    }
    return(ft_printf("Error\n specificare una mappa"));
}
    //data.img = mlx_xpm_file_to_image(data.mlx, img_path, &size, &size);
    //if (!data.img)
   //     return (0);
    //read_ber(data);
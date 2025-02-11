#include "so_long.h"

# include <unistd.h>
# include <stdlib.h>

int close_win(int keysym, t_data data)
{
    if(keysym == XK_Escape)
        {
            mlx_destroy_window(data.mlx, data.win);
            mlx_destroy_display(data.mlx);
        }
    free(data.win);
    return (0);
}

int     main()
{
    t_data  data;
    char    *img_path = "./table1x1.xpm";
    int     size = 200;
 
    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    data.win = mlx_new_window(data.mlx, 1920, 1080, "title window");
    if (!data.win)
        return(free(data.mlx), 1);
    
    data.img = mlx_xpm_file_to_image(data.mlx, img_path, &size, &size);
    if (!data.img)
        return (0);
    read_ber(data);
    mlx_hook(data.win, KeyPress, KeyPressMask, close_win, &data);
    mlx_mouse_hook(data.win, close_win, &data);
    mlx_loop(data.mlx);
    return (0);
}

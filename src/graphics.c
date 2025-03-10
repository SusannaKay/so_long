#include "so_long.h"

set_images(t_map *map)
{
    int img_width;
    int img_height;

    graphics->player = mlx_xmp_file_to_image(map->mlx, "path file", &img_height, &img_width);
    graphics->floor = mlx_xmp_file_to_image(map->mlx, "graphics/floor.xpm", &img_height, &img_width);
    graphics->wall = mlx_xmp_file_to_image(map->mlx, "graphics/wall.xpm", &img_height, &img_width);
    graphics->exit = mlx_xmp_file_to_image(map->mlx, "graphics/exit.xpm", &img_height, &img_width);
    graphics->collect = mlx_xmp_file_to_image(map->mlx, "graphics/collect.xpm", &img_height, &img_width);
}
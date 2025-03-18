#include "bonus_so_long.h"

static void	load_direction(t_map *map, char *dir, int i)
{
	int		size;
	char	*path;

	size = TILESIZE;
	path = ft_strjoin(dir, "0.xpm");
	map->animation->frames[i][0] = mlx_xpm_file_to_image(map->mlx, path, &size,
			&size);
	free(path);
	path = ft_strjoin(dir, "1.xpm");
	map->animation->frames[i][1] = mlx_xpm_file_to_image(map->mlx, path, &size,
			&size);
	free(path);
	path = ft_strjoin(dir, "2.xpm");
	map->animation->frames[i][2] = mlx_xpm_file_to_image(map->mlx, path, &size,
			&size);
	free(path);
	path = ft_strjoin(dir, "3.xpm");
	map->animation->frames[i][3] = mlx_xpm_file_to_image(map->mlx, path, &size,
			&size);
	free(path);
}

void	load_player_sprites(t_map *map)
{
	load_direction(map, "graphics/back", 0);
	load_direction(map, "graphics/front", 1);
	load_direction(map, "graphics/left", 2);
	load_direction(map, "graphics/right", 3);
	map->animation->current_frame = 0;
	map->animation->frame_delay = 0;
	map->animation->direction = 1;
}
int	update_player_animation(t_map *map)
{
	if (map->animation->frame_delay++ >= 500)
	{
		map->animation->current_frame = (map->animation->current_frame + 1) % 4;
		map->animation->frame_delay = 0;
	}
	return (0);
}
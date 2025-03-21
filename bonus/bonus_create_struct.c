#include "bonus_so_long.h"

t_map	*create_tmap(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_map(map);
	return (map);
}
t_graphics	*create_tgraphics(t_map *map)
{
	map->graphics = malloc(sizeof(t_graphics));
	if (!map->graphics)
		return (NULL);
	init_graphics(map->graphics);
	return (map->graphics);
}

t_animation	*create_tanimation(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->animation = malloc(sizeof(t_animation));
	if (!map->animation)
		return (NULL);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			map->animation->frames[i][j] = NULL;
			j++;
		}
		i++;
	}
	map->animation->current_frame = 0;
	map->animation->frame_delay = 0;
	map->animation->direction = 1;
	return (map->animation);
}
t_enemy	*create_tenemy(t_map *map)
{
	map->enemy = malloc(sizeof(t_enemy));
	if (!map->enemy)
		return (NULL);
	init_enemy(map);
	return (map->enemy);
}

t_map	*create_struct(t_map *map)
{
	// map = create_tmap(map);
	if (!map)
		exit_game(map, "Error:\nMap struct is NULL\n");
	// read_map(map);
	// verify_map(map);
	map->graphics = create_tgraphics(map);
	if (!map->graphics)
		exit_game(map, "Error:\nGraphics pointer is null\n");
	ft_printf("grafiche create\n");
	map->animation = create_tanimation(map);
	if (!map->animation)
		exit_game(map, "Error:\nAnimation pointer is null\n");
	ft_printf("animation create\n");
	map->enemy = create_tenemy(map);
	if (!map->enemy)
		exit_game(map, "Error:\nEnemy pointer is null\n");
	ft_printf("enemy create\n");
	return (map);
}

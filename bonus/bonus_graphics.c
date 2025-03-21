/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_graphics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 08:12:45 by skayed            #+#    #+#             */
/*   Updated: 2025/03/15 08:12:46 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

static void	set_images(t_map *map)
{
	int	img_size;

	img_size = TILESIZE;
	map->graphics->player = mlx_xpm_file_to_image(map->mlx,
			"graphics/front0.xpm", &img_size, &img_size);
	if (!map->graphics->player)
		exit_game(map, "Error:\nImage Player not loaded.");
	map->graphics->floor = mlx_xpm_file_to_image(map->mlx, "graphics/floor.xpm",
			&img_size, &img_size);
	if (!map->graphics->floor)
		exit_game(map, "Error:\nImage Floor not loaded.");
	map->graphics->wall = mlx_xpm_file_to_image(map->mlx, "graphics/wall.xpm",
			&img_size, &img_size);
	if (!map->graphics->wall)
		exit_game(map, "Error:\nImage Wall not loaded.");
	map->graphics->collect = mlx_xpm_file_to_image(map->mlx,
			"graphics/collect.xpm", &img_size, &img_size);
	if (!map->graphics->collect)
		exit_game(map, "Error:\nImage Collect not loaded.");
	map->graphics->exit = mlx_xpm_file_to_image(map->mlx, "graphics/exit.xpm",
			&img_size, &img_size);
	if (!map->graphics->exit)
		exit_game(map, "Error:\nImage Exit not loaded.");
	map->graphics->enemy = mlx_xpm_file_to_image(map->mlx, "graphics/enemy.xpm",
			&img_size, &img_size);
	if (!map->graphics->enemy)
		exit_game(map, "Error:\nImage Enemy not loaded.");
}

static void	put_image(t_map *map, void *image, int x, int y)
{
	if (!image)
		exit_game(map, "Error:\nImage not loaded.");
	mlx_put_image_to_window(map->mlx, map->win, image, (x * TILESIZE), (y
			* TILESIZE));
}

void	render_map(t_map *map, int n)
{
	int	x;
	int	y;

	x = 0;
	if (n == 0)
		set_images(map);
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '1')
				put_image(map, map->graphics->wall, x, y);
			if (map->map[y][x] == '0')
				put_image(map, map->graphics->floor, x, y);
			if (map->map[y][x] == 'C')
				put_image(map, map->graphics->collect, x, y);
			if (map->map[y][x] == 'E')
				put_image(map, map->graphics->exit, x, y);
			if (map->map[y][x] == 'P')
				put_image(map,
					map->animation->frames[map->animation->direction][map->animation->current_frame],
					x, y);
			if (map->map[y][x] == 'A')
				put_image(map, map->graphics->enemy, x, y);
			x++;
		}
		y++;
	}
	display_moves(map);
}

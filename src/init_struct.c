/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:32:51 by skayed            #+#    #+#             */
/*   Updated: 2025/03/14 13:43:46 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_map(t_map *map)
{
	map->filename = NULL;
	map->map = NULL;
	map->mlx = NULL;
	map->win = NULL;
	map->graphics = NULL;
	map->len_row = 0;
	map->rows = 0;
	map->collect = 0;
	map->moves = 0;
	map->score = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->tilesize = TILESIZE;
	map->p_counter = 0;
	map->e_counter = 0;
}

static void	init_graphics(t_graphics *graphics)
{
	graphics->collect = NULL;
	graphics->player = NULL;
	graphics->floor = NULL;
	graphics->wall = NULL;
	graphics->exit = NULL;
}

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

t_map	*create_struct(t_map *map)
{
	if (!map)
		exit_game(map, "Error:\nMap struct is NULL\n");
	map->graphics = create_tgraphics(map);
	if (!map->graphics)
		exit_game(map, "Error:\nGraphics pointer is null\n");
	return (map);
}

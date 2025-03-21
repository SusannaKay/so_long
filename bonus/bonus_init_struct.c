/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 08:12:55 by skayed            #+#    #+#             */
/*   Updated: 2025/03/18 16:09:14 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	init_map(t_map *map)
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
}
void	init_graphics(t_graphics *graphics)
{
	graphics->collect = NULL;
	graphics->player = NULL;
	graphics->floor = NULL;
	graphics->wall = NULL;
	graphics->exit = NULL;
	graphics->enemy = NULL;
}

void	init_enemy(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'A')
			{
				map->enemy->x = x;
				map->enemy->y = y;
				map->enemy->direction = 1;
				map->enemy->frame_delay = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 11:33:39 by skayed            #+#    #+#             */
/*   Updated: 2025/03/23 06:32:07 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

int	enemy_patrol(t_map *map)
{
	int	next_x;

	if (map->enemy->frame_delay++ < 150)
		return (0);
	map->enemy->frame_delay = 0;
	next_x = map->enemy->x + map->enemy->direction;
	if (map->map[map->enemy->y][next_x] == '1'
		|| map->map[map->enemy->y][next_x] == 'E'
		|| map->map[map->enemy->y][next_x] == 'A'
		|| map->map[map->enemy->y][next_x] == 'C')
		map->enemy->direction *= -1;
	else
	{
		if (map->map[map->enemy->y][next_x] == 'P')
			return (exit_game(map, "You Loose!\n"), 0);
		if (map->map[map->enemy->y][next_x] != 'C')
		{
			map->map[map->enemy->y][map->enemy->x] = '0';
			map->enemy->x = next_x;
			map->map[map->enemy->y][map->enemy->x] = 'A';
		}
	}
	return (0);
}

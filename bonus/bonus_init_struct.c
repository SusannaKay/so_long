/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 08:12:55 by skayed            #+#    #+#             */
/*   Updated: 2025/03/15 08:25:18 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

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
}
static void	init_graphics(t_graphics *graphics)
{
	graphics->collect = NULL;
	graphics->player = NULL;
	graphics->floor = NULL;
	graphics->wall = NULL;
	graphics->exit = NULL;
	graphics->enemy = NULL;
}
t_map	*create_tmap(t_map *map)
{
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_map(map);
	return (map);
}
t_graphics	*create_tgraphics(t_graphics *graphics)
{
	graphics = malloc(sizeof(t_graphics));
	if (!graphics)
		return (NULL);
	init_graphics(graphics);
	return (graphics);
}

t_animation *create_tanimation(t_animation *animation)
{
    int i;
    int j;

    i = 0;
    animation = malloc(sizeof(t_animation));
    if (!animation)
        return (NULL);
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            animation->frames[i][j] = NULL;
            j++;
        }
        i++;
    }
    animation->current_frame = 0;
    animation->frame_delay = 0;
    animation->direction = 0;
    return (animation);
}

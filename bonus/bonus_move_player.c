/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_move_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 08:13:09 by skayed            #+#    #+#             */
/*   Updated: 2025/03/15 08:13:10 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	update_position(int keysym, t_map *map, int *new_x, int *new_y)
{
	*new_x = map->p_x;
	*new_y = map->p_y;
	if (keysym == UP)
		*new_y -= 1;
	if (keysym == DOWN)
		*new_y += 1;
	if (keysym == LEFT)
		*new_x -= 1;
	if (keysym == RIGHT)
		*new_x += 1;
}

int	move_player(int keysym, t_map *map)
{
	int	new_x;
	int	new_y;

	update_position(keysym, map, &new_x, &new_y);
	if (keysym != UP && keysym != DOWN && keysym != LEFT && keysym != RIGHT)
		return (1);
	update_position(keysym, map, &new_x, &new_y);
	if (map->map[new_y][new_x] == 'E' && map->score == map->collect)
		return (exit_game(map, "You win!\n"), 0);
	if (map->map[new_y][new_x] == 'A')
		return (exit_game(map, "You Loose!\n"), 0);
	else if (map->map[new_y][new_x] == 'E' && map->score != map->collect)
		ft_printf("You must collect all the cookies!\n");
	if (map->map[new_y][new_x] != '1' && map->map[new_y][new_x] != 'E')
	{
		map->map[map->p_y][map->p_x] = '0';
		if (map->map[new_y][new_x] == 'C')
			map->score++;
		map->map[new_y][new_x] = 'P';
		map->moves++;
		if (keysym == UP)
            map->animation->direction = 0;
        else if (keysym == DOWN)
            map->animation->direction = 1;
        else if (keysym == LEFT)
            map->animation->direction = 2;
        else if (keysym == RIGHT)
            map->animation->direction = 3;
        update_player_animation(map);
		map->p_x = new_x;
		map->p_y = new_y;
		return (render_map(map, 1), 0);
	}
	return (1);
}

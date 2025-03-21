/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:32:59 by skayed            #+#    #+#             */
/*   Updated: 2025/03/14 14:16:47 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_graphics(int keysym, t_map *map)
{
	if (map->graphics->player)
		mlx_destroy_image(map->mlx, map->graphics->player);
	if (keysym == UP)
		map->graphics->player = mlx_xpm_file_to_image(map->mlx,
				"graphics/back0.xpm", &map->tilesize, &map->tilesize);
	if (keysym == DOWN)
		map->graphics->player = mlx_xpm_file_to_image(map->mlx,
				"graphics/front0.xpm", &map->tilesize, &map->tilesize);
	if (keysym == LEFT)
		map->graphics->player = mlx_xpm_file_to_image(map->mlx,
				"graphics/left0.xpm", &map->tilesize, &map->tilesize);
	if (keysym == RIGHT)
		map->graphics->player = mlx_xpm_file_to_image(map->mlx,
				"graphics/right0.xpm", &map->tilesize, &map->tilesize);
}

static void	update_position(int keysym, t_map *map, int *new_x, int *new_y)
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
	update_graphics(keysym, map);
}

int	move_player(int keysym, t_map *map)
{
	int	new_x;
	int	new_y;

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
		ft_printf("Moves number: %d\n", map->moves);
		map->p_x = new_x;
		map->p_y = new_y;
		return (render_map(map, 1), 0);
	}
	return (1);
}

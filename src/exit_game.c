/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:32:18 by skayed            #+#    #+#             */
/*   Updated: 2025/03/13 19:38:10 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->map)
	{
		i = 0;
		while (map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
	if (map->filename)
		free(map->filename);
	if (map->graphics)
		free(map->graphics);
	free(map);
}

static void	free_graphics(t_map *map)
{
	if (map->graphics)
	{
		if (map->graphics->collect)
		{
			mlx_destroy_image(map->mlx, map->graphics->collect);
			map->graphics->collect = NULL;
		}
		if (map->graphics->player)
		{
			mlx_destroy_image(map->mlx, map->graphics->player);
			map->graphics->player = NULL;
		}
		if (map->graphics->floor)
		{
			mlx_destroy_image(map->mlx, map->graphics->floor);
			map->graphics->floor = NULL;
		}
		if (map->graphics->wall)
		{
			mlx_destroy_image(map->mlx, map->graphics->wall);
			map->graphics->wall = NULL;
		}
		if (map->graphics->exit)
		{
			mlx_destroy_image(map->mlx, map->graphics->exit);
			map->graphics->exit = NULL;
		}
	}
}

int	exit_game(t_map *map, const char *error_message)
{
	if (error_message)
		ft_printf("%s\n", error_message);
	if (map)
	{
		if (map->graphics)
			free_graphics(map);
		if (map->mlx)
			mlx_loop_end(map->mlx);
		if (map->mlx && map->win)
		{
			mlx_destroy_window(map->mlx, map->win);
			map->win = NULL;
		}
		if (map->mlx)
		{
			mlx_destroy_display(map->mlx);
			free(map->mlx);
			map->mlx = NULL;
		}
		free_map(map);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:32:23 by skayed            #+#    #+#             */
/*   Updated: 2025/03/14 18:35:49 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_rectangular(t_map *map)
{
	int	i;
	int	len_row;
	int	num_rows;

	num_rows = 0;
	i = 0;
	len_row = ft_strlen(map->map[i]);
	while (map->map[i] != NULL)
	{
		if (ft_strlen(map->map[i]) != len_row)
			return (ft_printf("Error:\nMap not valid\n"), -1);
		i++;
	}
	num_rows++;
	if (num_rows == len_row)
		return (ft_printf("Error:\nThe map must be rectangular\n"), -1);
	return (0);
}

static int	is_closed(char **map)
{
	int	i;
	int	len_row;
	int	last_row;

	i = 0;
	last_row = 0;
	while (map[last_row] != NULL)
		last_row++;
	last_row--;
	while (map[i])
	{
		len_row = 0;
		while (map[i][len_row])
		{
			if ((i == 0 || i == last_row) && map[i][len_row] != '1')
				return (ft_printf("Error:\nThe map must be closed\n"), -1);
			len_row++;
		}
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (ft_printf("Error:\nThe map must be closed\n"), -1);
		i++;
	}
	return (0);
}

static int	process_cell(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'P')
	{
		if (!map->p_counter)
		{
			map->p_counter++;
			map->p_x = j;
			map->p_y = i;
		}
		else
			return (ft_printf("Error\nToo many P\n"), -1);
	}
	else if (map->map[i][j] == 'E')
	{
		if (!map->e_counter)
			map->e_counter++;
		else
			return (ft_printf("Error\nToo many E\n"), -1);
	}
	else if (map->map[i][j] == 'C')
		map->collect++;
	return (0);
}

static int	parsing_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (process_cell(map, i, j) < 0)
				return (-1);
			j++;
		}
		i++;
	}
	if (map->e_counter == 0 || map->p_counter == 0 || map->collect == 0)
		return (ft_printf("Error:\nMissing P, E or C in map\n"), -1);
	return (0);
}

int	verify_map(t_map *map)
{
	if (is_rectangular(map) < 0 || is_closed(map->map) < 0
		|| parsing_map(map) < 0)
		return (exit_game(map, "Error:\nMap not valid\n"), -1);
	flood_fill(map);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 08:13:22 by skayed            #+#    #+#             */
/*   Updated: 2025/03/15 08:13:23 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

static void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
}

static void	fill_char(char **matrix, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->len_row || y >= map->rows)
		return ;
	if ((matrix[y][x] == '1' || matrix[y][x] == 'F' || matrix[y][x] == 'A'))
		return ;
	if (matrix[y][x] == 'E')
	{
		matrix[y][x] = 'F';
		return ;
	}
	matrix[y][x] = 'F';
	fill_char(matrix, x + 1, y, map);
	fill_char(matrix, x - 1, y, map);
	fill_char(matrix, x, y + 1, map);
	fill_char(matrix, x, y - 1, map);
}

static int	check_matrix(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'C' || matrix[i][j] == 'E')
			{
				free_matrix(matrix);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	flood_fill(t_map *map)
{
	char	target;
	int		i;
	char	**matrix;

	target = '1';
	i = 0;
	matrix = malloc((map->rows + 1) * sizeof(char *));
	if (!matrix)
		return (exit_game(map, "Error:\nFlood fill failed."), -1);
	while (i < map->rows)
	{
		matrix[i] = ft_strdup(map->map[i]);
		if (!matrix[i])
		{
			free_matrix(matrix);
			return (exit_game(map, "Error:\nFlood fill failed."), -1);
		}
		i++;
	}
	matrix[i] = NULL;
	fill_char(matrix, map->p_x, map->p_y, map);
	if (check_matrix(matrix) < 0)
		return (exit_game(map, "Error:\nPath is not valid\n"), -1);
	free_matrix(matrix);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_display_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:24:13 by skayed            #+#    #+#             */
/*   Updated: 2025/03/15 08:11:30 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	display_moves(t_map *map)
{
	char *moves;
	char *temp;
	int i;
	int j;

	temp = ft_itoa(map->moves);
	if (!temp)
		return;
	moves = ft_strjoin("Moves: ", temp);
	free(temp);
	if (!moves)
		return;
	i = 10;
	while (i < 40)
	{
		j = 10;
		while (j < 200)  
		{
			mlx_pixel_put(map->mlx, map->win, j, i, 0x000000);
			j++;
		}
		i++;
	}
	mlx_string_put(map->mlx, map->win, 10, 25, 0xFFFFFF, moves);
	free(moves);
}

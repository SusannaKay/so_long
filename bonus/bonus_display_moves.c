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
	char	*moves;
	char	*temp;

	temp = ft_itoa(map->moves);
	if (!temp)
		return ;
	moves = ft_strjoin("Moves: ", temp);
	free(temp);
	if (!moves)
		return ;
	_string_put(map->mlx, map->win, 10, 25, 0x000000, moves);
	free(moves);
}

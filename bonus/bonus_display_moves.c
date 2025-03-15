/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_display_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:24:13 by skayed            #+#    #+#             */
/*   Updated: 2025/03/14 20:27:12 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	display_moves(t_map *map)
{
	char *moves;
	char *temp;
	int i;
	int j;

	// Crea la stringa per il contatore delle mosse
	temp = ft_itoa(map->moves);
	if (!temp)
		return;
	moves = ft_strjoin("Moves: ", temp);
	free(temp); // Libera la memoria di ft_itoa
	if (!moves)
		return;

	// Cancella l'area dove verrà scritto il testo
	i = 10;
	while (i < 40)  // Cancella un'area più larga per evitare sovrapposizioni
	{
		j = 10;
		while (j < 200)  
		{
			mlx_pixel_put(map->mlx, map->win, j, i, 0x000000); // Nero per cancellare
			j++;
		}
		i++;
	}

	// Scrive il testo in bianco
	mlx_string_put(map->mlx, map->win, 10, 25, 0xFFFFFF, moves);

	// Libera la memoria della stringa concatenata
	free(moves);
}

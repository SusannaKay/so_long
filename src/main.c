/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:32:55 by skayed            #+#    #+#             */
/*   Updated: 2025/03/13 19:32:34 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	create_window(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		free(map);
	map->win = mlx_new_window(map->mlx, (TILESIZE * map->len_row), (TILESIZE
				* map->rows), "So Long");
	if (!map->win)
		exit_game(map, "Error:\nWindow not created");
}

static int	key_down(int keysym, t_map *map)
{
	if (keysym == XK_Escape)
		exit_game(map, "Quit program by user");
	else
		move_player(keysym, map);
	return (0);
}

static void	create_loop(t_map *map)
{
	mlx_hook(map->win, KeyPress, KeyPressMask, key_down, map);
	mlx_hook(map->win, 17, 0L, exit_game, map);
	mlx_loop(map->mlx);
}

int	main(int argc, char *argv[])
{
	t_map		*map;
	t_graphics	*graphics;

	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
			return (ft_printf("Error\nFile format not valid, use .ber"), 1);
		map = create_tmap(map);
		if (!map)
			return (ft_printf("Error\nFailed to create map"), 1);
		map->filename = ft_strjoin("maps/", argv[1]);
		if (!map->filename)
			exit_game(map, "Error:\nFilename not found");
		read_map(map);
		verify_map(map);
		create_struct(map);
		create_window(map);
		render_map(map, 0);
		create_loop(map);
		return (0);
	}
	return (ft_printf("Error\nYou need a map to play the game"), 1);
}

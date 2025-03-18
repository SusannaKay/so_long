/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 08:13:03 by skayed            #+#    #+#             */
/*   Updated: 2025/03/18 10:38:56 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

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
		exit_game(map, "Program quit by user");
	else
		move_player(keysym, map);
	return (0);
}
static int game_loop(t_map *map)
{
    update_player_animation(map);
    render_map(map, 1);
    return (0);
}
static void	create_loop(t_map *map)
{
	mlx_hook(map->win, KeyPress, KeyPressMask, key_down, map);
	mlx_hook(map->win, 17, 0L, exit_game, map);
	mlx_loop_hook(map->mlx, game_loop, map);
	mlx_loop_hook(map->mlx, enemy_patrol, map);
	mlx_loop(map->mlx);
}
int	main(int argc, char *argv[])
{
	t_map		*map;
	t_graphics	*graphics;
	t_animation	*animation;

	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
			return (ft_printf("Error\nFile format not valid, use .ber"), 1);
		map = create_tmap(map);
		map->filename = ft_strjoin("bonus/maps/", argv[1]);
		if (!map->filename)
			exit_game(map, "Error:\nFilename not found");
		read_map(map);
		verify_map(map);
		create_struct(map);
		// map->graphics = create_tgraphics(graphics);
		// if (!map->graphics)
		// { 
		// 	ft_printf("Error:\nGraphics pointer is null");
		// 	return (0);
		// }
		// map->animation = create_tanimation(animation);
		// if (!map->animation)
		// {
		// 	ft_printf("Error:\nAnimation pointer is null");
		// 	return (0);
		// }
		create_window(map);
		ft_printf("pointer win create\n");
		load_player_sprites(map);
		ft_printf("sprites create\n");
		render_map(map, 0);
		ft_printf("primo rendering\n");
		create_loop(map);
		return (0);
	}
	return (ft_printf("Error\nYou need a map to play the game"), 1);
}

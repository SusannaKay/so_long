/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_exit_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 08:13:26 by skayed            #+#    #+#             */
/*   Updated: 2025/03/15 08:13:27 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

static void free_map(t_map *map)
{
    int i;

    if (!map)
        return;
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

static void free_graphics(t_map *map)
{
    if (map->graphics->collect)
        mlx_destroy_image(map->mlx, map->graphics->collect);
    if (map->graphics->player)
        mlx_destroy_image(map->mlx, map->graphics->player);
    if (map->graphics->floor)
    mlx_destroy_image(map->mlx, map->graphics->floor);
    if (map->graphics->wall)
        mlx_destroy_image(map->mlx, map->graphics->wall);
    if (map->graphics->exit)
        mlx_destroy_image(map->mlx, map->graphics->exit);
    if (map->graphics->enemy)
        mlx_destroy_image(map->mlx, map->graphics->enemy);
}

int exit_game(t_map *map, const char *error_message)
{
    if (ft_strncmp(error_message, "!", ft_strlen(error_message)) == 0)
        error_message = NULL;
    if (error_message)
        ft_printf("%s\n", error_message);
    free_graphics(map);
    mlx_loop_end(map->mlx);
    if (map)
    {
        if (map->mlx && map->win)
            mlx_destroy_window(map->mlx, map->win);
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

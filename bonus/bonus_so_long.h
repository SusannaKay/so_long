/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skayed <skayed@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 08:13:13 by skayed            #+#    #+#             */
/*   Updated: 2025/03/15 08:24:57 by skayed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILESIZE 64
# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

typedef struct s_map
{
	char				*filename;
	char				**map;
	void				*mlx;
	void				*win;
	struct s_graphics	*graphics;
	struct s_animation	*animation;
	int					len_row;
	int					rows;
	int					collect;
	int					p_x;
	int					p_y;
	int					moves;
	int					score;
}						t_map;

typedef struct s_graphics
{
	void				*player;
	void				*floor;
	void				*wall;
	void				*exit;
	void				*collect;
	void				*enemy;
}						t_graphics;

typedef struct s_enemy
{
    int x;
    int y;
    int direction;
} t_enemy;

typedef struct s_animation
{
	void				*frames[4][4];
	int					current_frame;
	int					frame_delay;
	int					direction;
}						t_animation;

int						verify_map(t_map *map);
void					read_map(t_map *map);
t_map					*create_tmap(t_map *map);
t_graphics				*create_tgraphics(t_graphics *graphics);
t_animation				*create_tanimation(t_animation *animation);
int						exit_game(t_map *map, const char *error_message);
int						flood_fill(t_map *map);
void					render_map(t_map *map, int n);
int						move_player(int keycode, t_map *map);
void					display_moves(t_map *map);
int						update_player_animation(t_map *map);
void load_player_sprites(t_map *map);
#endif

//valgrind -s --leak-check=full --show-leak-kinds=all
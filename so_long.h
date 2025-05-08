/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:26:36 by ciso              #+#    #+#             */
/*   Updated: 2025/05/08 16:30:04 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		move_count;

	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
}			t_game;

void		init_game(t_game *game);
void		parse_map(char *file, t_game *game);
void		free_map(char **map);
void		draw_map(t_game *game);
void		check_rectangular(t_game *game);
void		check_walls(t_game *game);
void		check_elements(t_game *game);
void		scan_elements(t_game *game, int *p, int *c, int *e);
int			handle_input(int keycode, void *param);
void		move_player(t_game *game, int dx, int dy);

#endif

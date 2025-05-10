/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:24:45 by ciso              #+#    #+#             */
/*   Updated: 2025/05/10 18:52:55 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "sprites/link.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, "sprites/ruby.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &w, &h);

	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_collectible || !game->img_exit)
	{
		write(2, "Error\nError loading image\n", 26);
		close_game(game);
	}
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, "Error\nmlx init error\n", 21);
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(
		game->mlx,
		game->map_width * TILE_SIZE,
		game->map_height * TILE_SIZE,
		"So Long with Link"
	);
	if (!game->win)
	{
		write(2, "Error\nwindow creation error\n", 28);
		exit(EXIT_FAILURE);
	}
	game->last_was_exit = 0;
	game->move_count = 0;
	load_images(game);     
	draw_map(game);    
}



int 	handle_close(t_game *game)
{
	close_game(game);
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:24:45 by ciso              #+#    #+#             */
/*   Updated: 2025/05/08 15:37:56 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "so_long.h"
static void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &w, &h);
printf("img_wall loaded: %p (%dx%d)\n", game->img_wall, w, h);

game->img_floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm", &w, &h);
printf("img_floor loaded: %p (%dx%d)\n", game->img_floor, w, h);

game->img_player = mlx_xpm_file_to_image(game->mlx, "sprites/link.xpm", &w, &h);
printf("img_player loaded: %p (%dx%d)\n", game->img_player, w, h);

game->img_collectible = mlx_xpm_file_to_image(game->mlx, "sprites/ruby.xpm", &w, &h);
printf("img_collectible loaded: %p (%dx%d)\n", game->img_collectible, w, h);

game->img_exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &w, &h);
printf("img_exit loaded: %p (%dx%d)\n", game->img_exit, w, h);


	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_collectible || !game->img_exit)
	{
		write(2, "Error\nÉchec de chargement des images .xpm\n", 43);
		exit(EXIT_FAILURE);
	}
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, "Erreur d'initialisation MLX\n", 29);
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
		write(2, "Erreur de création de fenêtre\n", 30);
		exit(EXIT_FAILURE);
	}

	load_images(game);     
	draw_map(game);    
}


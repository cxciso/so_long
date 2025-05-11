/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:18:45 by ciso              #+#    #+#             */
/*   Updated: 2025/05/10 18:50:24 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_values(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_collectible = NULL;
	game->img_exit = NULL;
	game->collectibles = 0;
	game->last_was_exit = 0;
	game->move_count = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long map.ber\n", 26);
		return (1);
	}
	init_values(&game);
	parse_map(argv[1], &game);
	init_game(&game);
	draw_map(&game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}

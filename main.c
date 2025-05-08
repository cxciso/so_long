/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:18:45 by ciso              #+#    #+#             */
/*   Updated: 2025/05/08 18:32:51 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Usage: ./so_long map.ber\n", 26);
		return (1);
	}
	parse_map(argv[1], &game);
	printf("Map lue ! Taille : %d x %d\n", game.map_width, game.map_height);
	for (int i = 0; game.map[i]; i++)
		printf("%s", game.map[i]);
	init_game(&game);
	printf("Before draw_map\n");
	draw_map(&game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_loop(game.mlx);
	return (0);
}

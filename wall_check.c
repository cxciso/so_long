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
#include "so_long.h"
#include <string.h>

void	check_horizontal_walls(t_game *game)
{
	int	i;
	int	last;

	i = 0;
	last = game->map_height - 1;
	while (i < game->map_width - 1)
	{
		if (game->map[0][i] != '1' || game->map[last][i] != '1')
		{
			write(2, "Error\nHorizontal walls aren't closed\n", 37);
			close_game(game, 1);
		}
		i++;
	}
}

void	check_vertical_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
		{
			write(2, "Error\nVertical walls aren't closed\n", 35);
			close_game(game, 1);
		}
		i++;
	}
}

void	check_walls(t_game *game)
{
	check_horizontal_walls(game);
	check_vertical_walls(game);
}

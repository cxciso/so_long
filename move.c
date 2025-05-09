/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:36:11 by ciso              #+#    #+#             */
/*   Updated: 2025/05/06 16:46:38 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "so_long.h"
#include <stdlib.h>

int	handle_input(int keycode, void *param)
{
	t_game *game = (t_game *)param;
	if (keycode == 65362 || keycode == 119) // Z
		move_player(game, 0, -1);
	else if (keycode == 65364 || keycode == 115) // S
		move_player(game, 0, 1);
	else if (keycode == 65361 || keycode == 97) // Q
		move_player(game, -1, 0);
	else if (keycode == 65363 || keycode == 100) // D
		move_player(game, 1, 0);
	else if (keycode == 65307) // ESC
	close_game(game);
	return (0);
}

void move_player2(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E')
		game->last_was_exit = 1;
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	ft_putnbr_fd(game->move_count, 1);
	write(1, "\n", 1);
	draw_map(game);
}
void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->collectibles--;
	if (game->map[new_y][new_x] == 'E')
		if (game->collectibles == 0)
		{
			write(1, "🪇  You win 🪇\n", 19);
			close_game(game);
		}
	if (game->last_was_exit)
	{
		game->map[game->player_y][game->player_x] = 'E';
		game->last_was_exit = 0;
	}
	else
		game->map[game->player_y][game->player_x] = '0';
	move_player2(game, new_x, new_y);
}





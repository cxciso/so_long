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
int	handle_input(int keycode, void *param)
{
	t_game *game = (t_game *)param;

	if (keycode == 119) // Z
		move_player(game, 0, -1);
	else if (keycode == 115) // S
		move_player(game, 0, 1);
	else if (keycode == 97) // Q
		move_player(game, -1, 0);
	else if (keycode == 100) // D
		move_player(game, 1, 0);
	else if (keycode == 65307) // ESC
		exit(0);
	return (0);
}
void	move_player(t_game *game, int dx, int dy)
{
	int	new_x = game->player_x + dx;
	int	new_y = game->player_y + dy;


	if (game->map[new_y][new_x] == '1')
		return ;


	if (game->map[new_y][new_x] == 'C')
		game->map[new_y][new_x] = '0';

	if (game->map[new_y][new_x] == 'E')
	{
		write(1, "Tu as gagné !\n", 14);
		exit(0);
	}

	game->player_x = new_x;
	game->player_y = new_y;
	game->move_count++;
	ft_putnbr_fd(game->move_count, 1);
	write(1, "\n", 1);
	draw_map(game);
}



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

void	check_rectangular(t_game *game)
{
	int	i;
	int	len;
	int	val;

	i = 0;
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		val = ft_strlen(game->map[i]);
		if (ft_strchr(game->map[i], '\n') == 0)
			val += 1;
		if (val != len)
		{
			write(2, "Error\nMap isn't rectangular\n", 28);
			close_game(game, 1);
		}
		i++;
	}
}

void	validate_elements(t_game *game, int p, int c, int e)
{
	if (p != 1 || c < 1 || e != 1)
	{
		write(2, "Error\ninvalid element\n", 22);
		close_game(game, 1);
	}
}

void	check_wrong_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P')
			{
				write(2, "Error\nInvalid char\n", 19);
				close_game(game, 1);
			}
		}
	}
}

void	check_elements(t_game *game)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	scan_elements(game, &p, &c, &e);
	check_wrong_elements(game);
	validate_elements(game, p, c, e);
}

void	scan_elements(t_game *game, int *p, int *c, int *e)
{
	int	i;
	int	j;

	i = -1;
	game->collectibles = 0;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				(*p)++;
			}
			else if (game->map[i][j] == 'C')
			{
				game->collectibles++;
				(*c)++;
			}
			else if (game->map[i][j] == 'E')
				(*e)++;
		}
	}
}

#include "so_long.h"

void	check_horizontal_walls(t_game *game)
{
	int	i;
	int	last;

	i = 0;
	last = game->map_height - 1;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1' || game->map[last][i] != '1')
		{
			write(2, "Error\nHaut ou bas non fermés\n", 30);
			exit(EXIT_FAILURE);
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
		if (game->map[i][0] != '1' ||
			game->map[i][game->map_width - 1] != '1')
		{
			write(2, "Error\nGauche ou droite non fermés\n", 35);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_walls(t_game *game)
{
	check_horizontal_walls(game);
	check_vertical_walls(game);
}

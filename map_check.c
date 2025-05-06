#include "so_long.h"

void	check_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(game->map[0]);
	 printf("Map dimensions: %d x %d\n", game->map_height, game->map_width);
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != len)
		{
			write(2, "Error\nMap non rectangulaire\n", 29);
			exit(1);
		}
		i++;
	}
}

void	validate_elements(int p, int c, int e)
{
	if (p != 1 || c < 1 || e < 1)
	{
		write(2, "Error\nP = 1, C >= 1, E >= 1 requis\n", 35);
		exit(EXIT_FAILURE);
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
	validate_elements(p, c, e);
}

void	scan_elements(t_game *game, int *p, int *c, int *e)
{
	int	i;
	int	j;

	i = -1;
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
				(*c)++;
			else if (game->map[i][j] == 'E')
				(*e)++;
		}
	}
}

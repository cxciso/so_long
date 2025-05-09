#include "so_long.h"

void free_imgs(t_game *game)
{
    mlx_destroy_image(game->mlx, game->img_wall);
    mlx_destroy_image(game->mlx, game->img_floor);
    mlx_destroy_image(game->mlx, game->img_player);
    mlx_destroy_image(game->mlx, game->img_collectible);
    mlx_destroy_image(game->mlx, game->img_exit);
}

int	close_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
    free_imgs(game);
	if (game->mlx && game->win)
    {
		mlx_destroy_window(game->mlx, game->win);
    }
	free(game->win);
	free(game->mlx);
    free(game);
	exit(0);
}

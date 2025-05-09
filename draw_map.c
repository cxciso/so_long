#include "so_long.h"

#define TILE_SIZE 64


/*static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
}*/
static void	draw_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '0' || tile == 'P' || tile == 'C' || tile == 'E')
    mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
        x * TILE_SIZE, y * TILE_SIZE);

	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
			x * TILE_SIZE, y * TILE_SIZE);
}

void draw_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->map_height)
	{
		if (!game->map[y])
		{
			break;
		}
		x = 0;
		while (x < game->map_width)
		{
			draw_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

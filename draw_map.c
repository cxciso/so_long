#include "so_long.h"

#define TILE_SIZE 64


/*static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 64, y * 64);
}*/

static void draw_tile(t_game *game, char tile, int x, int y)
{
	void *img = NULL;

	if (tile == '1')
		img = game->img_wall;
	else if (tile == '0')
		img = game->img_floor;
	else if (tile == 'P')
		img = game->img_player;
	else if (tile == 'C')
		img = game->img_collectible;
	else if (tile == 'E')
		img = game->img_exit;

	if (!img)
	{
		printf("⚠️ Image NULL à la position [%d][%d] pour le tile '%c'\n", y, x, tile);
		exit(1);
	}

	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
}



void draw_map(t_game *game)
{
	int x;
	int y;

	printf("draw_map() appelé\n");  // 👈 ça dit que la fonction est appelée

	y = 0;
	while (y < game->map_height)
	{
		if (!game->map[y])
		{
			printf("game->map[%d] est NULL !\n", y);
			break;
		}
		x = 0;
		while (x < game->map_width)
		{
			printf("case [%d][%d] = %c\n", y, x, game->map[y][x]);  // 👈 pour chaque case
		draw_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

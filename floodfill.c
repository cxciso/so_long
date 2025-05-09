#include "so_long.h"

int	map_height(char **map)
{
    int	i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

void	free_map(char **map)
{
    int	i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

static void	fill(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'F')
        return ;
    map[y][x] = 'F';
    fill(map, x + 1, y);
    fill(map, x - 1, y);
    fill(map, x, y + 1);
    fill(map, x, y - 1);
}

static char	**copy_map(char **map, int height)
{
    char	**new_map;
    int		y;

    y = 0;
    new_map = malloc(sizeof(char *) * (height + 1));
    if (!new_map)
        return (NULL);
    while (map[y])
    {
        new_map[y] = ft_strdup(map[y]);
        if (!new_map[y])
            return (NULL);
        y++;
    }
    new_map[y] = NULL;
    return (new_map);
}

int	is_path_valid(t_game *game)
{
    char	**tmp_map;
    int		y;

    y = 0;
    tmp_map = copy_map(game->map, map_height(game->map));
    if (!tmp_map)
        return (0);
    fill(tmp_map, game->player_x, game->player_y);
    while (tmp_map[y])
    {
        if (ft_strchr(tmp_map[y], 'C') || ft_strchr(tmp_map[y], 'E'))
        {
            free_map(tmp_map);
            write(2, "Error\nNo path available\n", 24);
            close_game(game);
        }
        y++;
    }
    return (free_map(tmp_map), 1);
}

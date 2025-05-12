/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:50:01 by ciso              #+#    #+#             */
/*   Updated: 2025/05/02 14:56:12 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_lines(char *filename)
{
	int		fd;
	int		count;
	char	buf;
	int		ret;

	buf = 0;
	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	ret = read(fd, &buf, 1);
	while (ret > 0)
	{
		if (buf == '\n')
			count++;
		ret = read(fd, &buf, 1);
	}
	if (buf != '\n')
		count++;
	close(fd);
	return (count);
}

static void	read_map(char *filename, t_game *game, int lines)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	game->map = malloc(sizeof(char *) * (lines + 1));
	if (!game->map)
		exit(EXIT_FAILURE);
	game->map[i] = get_next_line(fd);
	while (game->map[i])
	{
		i++;
		game->map[i] = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}

void	parse_map(char *filename, t_game *game)
{
	int	lines;

	lines = count_lines(filename);
	if (lines <= 0)
	{
		write(2, "Error\nEmpty map\n", 16);
		exit(EXIT_FAILURE);
	}
	read_map(filename, game, lines);
	if (!game->map[0])
	{
		write(2, "Error\nEmpty file\n", 17);
		close_game(game, 1);
	}
	game->map_height = lines;
	game->map_width = ft_strlen(game->map[0]) - 1;
	check_rectangular(game);
	check_walls(game);
	check_elements(game);
	is_path_valid(game);
}

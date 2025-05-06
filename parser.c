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

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((ret = read(fd, &buf, 1)) > 0)
	{
		if (buf == '\n')
			count++;
	}
	close(fd);
	return (count);
}

static void	read_map(char *filename, t_game *game, int lines)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	game->map = malloc(sizeof(char *) * (lines + 1));
	if (!game->map)
		exit(EXIT_FAILURE);
	while (i < lines)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			break ;
		i++;
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
		write(2, "Error\nMap vide ou invalide\n", 28);
		exit(EXIT_FAILURE);
	}
	read_map(filename, game, lines);
	game->map_height = lines;
	game->map_width = ft_strlen(game->map[0]) - 1;
	check_rectangular(game);
	check_walls(game);
	check_elements(game);
}

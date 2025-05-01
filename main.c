/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:18:45 by ciso              #+#    #+#             */
/*   Updated: 2025/05/01 16:30:52 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	process(t_vars *vars)
{
	update_img(vars);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 0, close_win, vars);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac == 2)
	{
		vars = malloc(sizeof(t_vars));
		if (!vars)
			return (1);
		vars->arr = parser(vars, av[1]);
		if (!vars->arr)
			return (free(vars), 0);
		if (!init(vars))
			return (ft_free_t_vars(vars), 0);
		if (!process(vars))
			return (ft_free_t_vars(vars), 0);
		mlx_loop(vars->mlx);
	}
	else
		return (error("Usage: ./fdf <map.fdf>\n"), 1);
	return (ft_free_t_vars(vars), 0);
}
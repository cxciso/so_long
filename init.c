/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:24:45 by ciso              #+#    #+#             */
/*   Updated: 2025/05/01 16:25:00 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	win_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (0);
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "FDF by malapoug");
	if (!vars->win)
		return (0);
	vars->img = malloc(sizeof(t_data));
	if (!vars->img)
		return (0);
	vars->img->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	if (!vars->img->img)
		return (0);
	vars->img->addr = mlx_get_data_addr(vars->img->img, \
		&vars->img->bpp, &vars->img->line_length, &vars->img->endian);
	return (1);
}

int	init(t_vars *vars)
{
	if (!win_init(vars))
		return (0);
	return (1);
}
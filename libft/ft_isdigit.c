/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:55:52 by ciso              #+#    #+#             */
/*   Updated: 2024/11/04 15:40:29 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int a)
{
	if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}

// int	main(int argc, char *argv[])
// {
// 	int	i;

// 	i = 1;
// 	while (argv[i])
// 	{
// 		printf("RESULT : %d\n", ft_isdigit(atoi(argv[i])));
// 		i++;
// 	}
// 	return (0);
// }

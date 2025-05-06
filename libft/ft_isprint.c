/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:02:03 by ciso              #+#    #+#             */
/*   Updated: 2024/11/04 15:40:52 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int a)
{
	if (a >= 32 && a <= 126)
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
// 		printf("RESULT : %d\n", ft_isprint(atoi(argv[i])));
// 		i++;
// 	}
// 	return (0);
// }

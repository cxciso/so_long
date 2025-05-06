/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:57:07 by ciso              #+#    #+#             */
/*   Updated: 2024/11/04 16:12:16 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a)
{
	if (a >= 0 && a <= 127)
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
// 		printf("RESULT : %d\n", ft_isascii(atoi(argv[i])));
// 		i++;
// 	}
// 	return (0);
// }

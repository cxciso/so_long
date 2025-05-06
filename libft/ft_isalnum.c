/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:56:18 by ciso              #+#    #+#             */
/*   Updated: 2024/11/04 16:11:24 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if (ft_isalpha(a) || ft_isdigit(a))
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
// 		printf("RESULT : %d\n", ft_isalnum(atoi(argv[i])));
// 		i++;
// 	}
// 	return (0);
// }

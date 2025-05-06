/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:29:42 by ciso              #+#    #+#             */
/*   Updated: 2024/11/07 16:09:44 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int num)
{
	int		size;
	char	*str;

	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	if (num == 0)
		return (ft_strdup("0"));
	size = count(num);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while ((size > 0 && (num != 0 || str[size - 1] == '0')))
	{
		str[size - 1] = (num % 10) + '0';
		num = num / 10;
		size--;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:08:34 by ciso              #+#    #+#             */
/*   Updated: 2024/11/09 17:11:08 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*result;

	i = 0;
	j = 0;
	if (len > ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result || !s)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len && s[i])
		{
			result[j] = s[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}

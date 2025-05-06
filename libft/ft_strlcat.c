/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:08:27 by ciso              #+#    #+#             */
/*   Updated: 2024/11/06 16:42:16 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	c;
	unsigned int	i;

	c = ft_strlen(dst);
	i = 0;
	if (size <= c)
		return (size + ft_strlen((char *)src));
	while (c + i < size - 1 && src[i])
	{
		dst[c + i] = src[i];
		i++;
	}
	dst[c + i] = '\0';
	return (c + ft_strlen((char *)src));
}

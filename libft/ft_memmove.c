/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:42:13 by ciso              #+#    #+#             */
/*   Updated: 2024/11/06 16:22:50 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrs;
	unsigned char	*ptrd;
	size_t			i;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	i = 0;
	ptrs = (unsigned char *)src;
	ptrd = (unsigned char *)dest;
	if (ptrs < ptrd)
	{
		i = n;
		while (i > 0)
		{
			i--;
			ptrd[i] = ptrs[i];
		}
		return (dest);
	}
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return (dest);
}

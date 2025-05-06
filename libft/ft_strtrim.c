/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 21:21:13 by ciso              #+#    #+#             */
/*   Updated: 2024/11/09 16:36:43 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	end;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	i = 0;
	while (s1[i] && in_set(s1[i], set))
		i++;
	end = ft_strlen((char *)s1) - 1;
	while (in_set(s1[end], set))
		end--;
	if (end < i)
		return (ft_strdup(""));
	return (ft_substr(s1, i, end - i + 1));
}

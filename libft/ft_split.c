/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciso <ciso@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:20:01 by ciso              #+#    #+#             */
/*   Updated: 2024/11/04 16:56:27 by ciso             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;

	dup = (char *)malloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, n + 1);
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		start;

	tab = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			start = 0;
			while (s[start] && s[start] != c)
				start++;
			tab[i] = ft_strndup(s, start);
			if (!tab[i++])
				return (NULL);
			s += start;
		}
	}
	tab[i] = NULL;
	return (tab);
}

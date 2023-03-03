/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:16:14 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 16:17:18 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_strs(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			while (*s != c && *s)
				s++;
			i++;
		}
		else
			s++;
	}
	return (i);
}

static size_t	ft_count_chars(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char const	*ft_next_strs(char const *s, char c, int i)
{
	if (i == 0)
		while (*s && *s == c)
			s++;
	else
		while (*s && *s != c)
			s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	num_strs;
	char	**ptrs;

	if (!s)
		return (0);
	i = 0;
	num_strs = ft_count_strs(s, c) + 1;
	ptrs = (char **)ft_calloc(num_strs, sizeof(char *));
	if (!ptrs)
		return (0);
	ptrs[num_strs - 1] = NULL;
	while (i + 1 < num_strs)
	{
		s = ft_next_strs(s, c, 0);
		ptrs[i] = (char *)ft_calloc(ft_count_chars(s, c) + 1, sizeof(char));
		if (!ptrs[i])
			return (ft_free_strs(ptrs));
		ft_strlcpy(ptrs[i++], s, ft_count_chars(s, c) + 1);
		s = ft_next_strs(s, c, 1);
	}
	return (ptrs);
}

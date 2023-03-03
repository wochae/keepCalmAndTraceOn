/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:16:26 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 16:17:34 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (*str)
	{
		str++;
		i++;
	}
	while (i)
	{
		if (*str == (char)c)
			return (str);
		str--;
		i--;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}

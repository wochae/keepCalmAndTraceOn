/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:16:19 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 16:17:28 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(dst) > size)
		return (ft_strlen(src) + size);
	while (*dst != 0)
	{
		i++;
		dst++;
	}
	while ((i + 1 < size) && src[j] != 0)
	{
		*dst++ = src[j++];
		i++;
	}
	*dst = 0;
	while (src[j] != 0)
	{
		i++;
		j++;
	}
	return (i);
}

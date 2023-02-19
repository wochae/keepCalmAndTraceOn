#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;
	char *str;

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

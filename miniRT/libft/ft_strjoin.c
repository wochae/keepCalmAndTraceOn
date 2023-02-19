#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t i;
	size_t j;
	size_t len;
	char *str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len) + 1);
	if (str == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

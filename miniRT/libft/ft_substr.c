#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *str;
	size_t ourlen;

	if (s == NULL)
		return (NULL);
	i = 0;
	ourlen = ft_strlen(s);
	if (start >= ourlen)
		return (ft_strdup(""));
	if (ourlen - start < len)
		len = ourlen - start;
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

// str : abc len : 999999999999
// str : abc\000000000000000000000000000000000000000000
// -> str : abc\0

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (0);
	i = 0;
	while (i < len && ft_strlen(needle) + i <= len)
	{
		if (!ft_strncmp(haystack + i, needle, ft_strlen(needle)))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}

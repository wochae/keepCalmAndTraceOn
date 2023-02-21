#include "libft.h"

int	is_it(char ch, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_lefttrim(const char *str, const char *set)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (str[i])
	{
		if (is_it(str[i], set) == 1)
			value++;
		else
			return (value);
		i++;
	}
	return (value);
}

int	ft_righttrim(const char *str, const char *set)
{
	int	i;
	int	value;

	i = (int)ft_strlen(str) - 1;
	value = 0;
	while (i >= 0)
	{
		if (is_it(str[i], set) == 1)
			value++;
		else
			return (value);
		i--;
	}
	return (value);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	start = ft_lefttrim(s1, set);
	end = ft_righttrim(s1, set);
	if (start + end > (int)ft_strlen(s1))
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (((int)ft_strlen(s1) - (start + end) + 1)));
	if (str == NULL)
		return (NULL);
	while (i < ((int)ft_strlen(s1) - (start + end)))
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

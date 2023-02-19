#include "libft.h"

int ft_atoi(const char *str)
{
	int minus;
	int ret;

	ret = 0;
	minus = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	if (*str == '-' || *str == '+')
		return (0);
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			ret = ret * 10 + *str - '0';
		else
			break;
		str++;
	}
	return (ret * minus);
}

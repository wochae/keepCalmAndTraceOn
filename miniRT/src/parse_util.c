#include "minirt.h"

static void	check_sep(char *str, char sep, int num)
{
	while (*str)
	{
		if (*str == sep)
			num--;
		str++;
	}
	if (num)
		ft_error("wrong input : wrong number of separators");
}

t_color3	parse_color(char *str)
{
	char		**rgb;
	t_color3	color;

	check_sep(str, ',', 2);
	rgb = ft_split(str, ',');
	if (!rgb)
		ft_error("malloc failed");
	if (ft_strslen(rgb) != 3)
		ft_error("wrong input : color must have 3 numbers");
	color = (t_color3){ft_atod(rgb[0]), ft_atod(rgb[1]), ft_atod(rgb[2])};
	ft_free_strs(rgb);
	if (color.z < 0 || color.z > 255 || color.y < 0 || color.y > 255 || \
		color.x < 0 || color.x > 255)
		ft_error("wrong input : color must be 0 ~ 255");
	color = (t_color3){color.x / 255.0, color.y / 255.0, color.z / 255.0};
	return (color);
}

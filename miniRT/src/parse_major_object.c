#include "minirt.h"

void	parse_ambient(char **args, t_info *info)
{
	if (ft_strslen(args) != 3)
		ft_error("wrong input : 'A must be 3 arguments");
	info->amb.ratio = ft_atod(args[1]);
	if (info->amb.ratio < 0 || info->amb.ratio > 1)
		ft_error("wrong input : ambient ratio must be 0 ~ 1");
	info->amb.color = parse_color(args[2]);
}

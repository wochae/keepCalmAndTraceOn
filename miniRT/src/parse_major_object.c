#include "minirt.h"

void	parse_ambient(char **args, t_info *info)
{
	if (ft_strslen(args) != 3)
		ft_error("wrong input : 'A must have 3 arguments");
	info->ambient.ratio = ft_atod(args[1]);
	if (info->ambient.ratio < 0 || info->ambient.ratio > 1)
		ft_error("wrong input : ambient ratio must be 0 ~ 1");
	info->ambient.amount = mult_t(parse_color(args[2]), info->ambient.ratio);
}

void	parse_camera(char **args, t_info *info)
{
	if (ft_strslen(args) != 4)
		ft_error("wrong input : 'C' must have 4 arguments");
	info->cam.origin = parse_pt(args[1]);
	info->cam.dir = unit(parse_n_vec(args[2]));
	info->cam.fov = ft_atod(args[3]);
	if (info->cam.fov < 0 || info->cam.fov > 180)
		ft_error("wrong input : fov must have 0 ~180");
}

void	parse_light(char **args, t_info *info)
{
	if (ft_strslen(args) != 4)
		ft_error("wrong input : 'L' must have 4 arguments");
	info->light.origin = parse_pt(args[1]);
	info->light.ratio = ft_atod(args[2]);
	if (info->light.ratio < 0 || info->light.ratio > 1)
		ft_error("wrong input : light ratio must be 0 ~ 1");
    info->light.amount = color3(1.0, 1.0, 1.0);
}
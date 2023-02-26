#include "minirt.h"

void	parse_ambient(char **args, t_info *info)
{
	if (ft_strslen(args) != 3)
		ft_error("wrong input : 'A must have 3 arguments");
	info->ambient.ratio = ft_atod(args[1]);
	if (info->ambient.ratio < 0 || info->ambient.ratio > 1)
		ft_error("wrong input : ambient ratio must be 0 ~ 1");
	info->ambient.amount = parse_color(args[2]);
}

void	parse_camera(char **args, t_info *info)
{
	if (ft_strslen(args) != 4)
		ft_error("wrong input : 'C' must have 4 arguments");
	info->cam.origin = parse_pt(args[1]);
	info->cam.dir = parse_pt(args[2]);
	check_n_vec(info->cam.dir);
	info->cam.fov = ft_atod(args[3]);
	if (info->cam.fov < 0 || info->cam.fov > 180)
		ft_error("wrong input : fov must have 0 ~180");
}

void	parse_light(char **args, t_info *info)
{
	if (ft_strslen(args) != 4)
		ft_error("wrong input : 'L' must have 4 arguments");
	info->light.origin = parse_pt(args[1]);
	info->light.bright_ratio = ft_atod(args[2]);

}
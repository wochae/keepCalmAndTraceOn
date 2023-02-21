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

void	parse_camera(char **args, t_info *info)
{
	if (ft_strslen(args) != 4)
		ft_error("wrong input : 'C' must be 4 arguments");
	info->cam.orig = parse_pt(args[1]);
	info->cam.dir = parse_pt(args[2]);
	check_n_vec(info->cam.dir);
	info->cam.fov = ft_atod(args[3]);
	if (info->cam.fov < 0 || info->cam.fov > 180)
		ft_error("wrong input : fov must be 0 ~180");
}

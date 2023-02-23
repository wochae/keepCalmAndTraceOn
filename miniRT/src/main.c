#include <stdio.h>
#include "minirt.h"
#include "../mlx/mlx.h"

static void	parse(char *argv, t_info *info)
{
	char	*content;

	content = ft_strdup("");
	if (!content)
		ft_error("memory alloc failed");
	check_file_extension(argv);
	read_file(argv, &content);
	parse_to_info(content, info);
}

static void	ft_execve(t_info *info) // for testing
{
	t_ambient amb = info->ambient;
	t_cam cam = info->cam;
	t_light light = info->light;
	printf("%f\n", amb.ratio);
	printf("%f %f %f \n", amb.amount.x, amb.amount.y, amb.amount.z);
	printf("%f %f %f \n", cam.origin.x, cam.origin.y, cam.origin.z);
	printf("%f %f %f \n", cam.looking_side.x,cam.looking_side.y,cam.looking_side.z);
	printf("%f \n", cam.fov);
	printf("%f %f %f \n", light.origin.x, light.origin.y, light.origin.z);
	printf("%f \n", light.bright_ratio);
	printf("%f %f %f \n", light.amount.x, light.amount.y, light.amount.z);	
}

int	main(int argc, char **argv)
{
	t_info	info;

	ft_memset(&info, 0, sizeof(t_info));
	if (argc != 2)
		ft_error("wrong number of arguments");
	parse(argv[1], &info);
	ft_execve(&info);
	exit(0);
}
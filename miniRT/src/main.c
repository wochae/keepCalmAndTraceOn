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
	t_object *objs = info->objects;
	t_sphere 	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
	

	printf("amb ratio %f\n", amb.ratio);
	printf("amb amount %f %f %f \n", amb.amount.x, amb.amount.y, amb.amount.z);
	printf("cam pos %f %f %f \n", cam.origin.x, cam.origin.y, cam.origin.z);
	printf("cam dir %f %f %f \n", cam.looking_side.x,cam.looking_side.y,cam.looking_side.z);
	printf("cam fov %f \n", cam.fov);
	printf("lit pos %f %f %f \n", light.origin.x, light.origin.y, light.origin.z);
	printf("lit ratio %f \n", light.bright_ratio);
	printf("lit amount %f %f %f \n", light.amount.x, light.amount.y, light.amount.z);
	while (objs)
	{
		if (objs->type == SPHERE)
		{
			sp = (t_sphere *) objs->element;
			printf("sp\n%f, %f, %f \n%f \n%f, %f, %f\n", sp->center.x, sp->center.y, sp->center.z, sp->radius, sp->sp_rgb.x, sp->sp_rgb.y, sp->sp_rgb.y);
		}
		else if (objs->type == PLANE)
		{
			pl = (t_plane *) objs->element;
			printf("pl\n%f, %f, %f \n%f, %f, %f\n%f, %f, %f\n", pl->pos.x, pl->pos.y, pl->pos.z, pl->dir.x, pl->dir.y, pl->dir.z, pl->color.x, pl->color.y, pl->color.z);
		}
		else if (objs->type == CYLINDER)
		{
			cy = (t_cylinder *) objs->element;
			printf("cy\n%f, %f, %f \n%f, %f, %f \n%f \n%f, %f, %f, %f\n", cy->pos.x, cy->pos.y, cy->pos.z, cy->dir.x, cy->dir.y, cy->dir.z, cy->r, cy->height, cy->color.x, cy->color.y, cy->color.z);			
		}
		objs = objs->next;
	}

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
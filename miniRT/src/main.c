#include "minirt.h"

static void	parse(char *argv, t_info *info)
{
	char	*content;

	content = ft_strdup("");
	if (!content)
		ft_error("memory alloc failed");
	check_file_extension(argv);
	read_file(argv, &content);
	parse_to_info(content, info);
	mlx_setting(info);
	cam_setting(&info->cam);
}

void draw(t_info *info)
{
	int			i;
	int 		j;
	char		*dst;
	t_color3	colors;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			info->ray = ray_primary(info->cam, \
			(double)i / (WIDTH - 1), \
			(HEIGHT - 1 - (double)j) / (HEIGHT - 1));
			colors = ray_color(info->ray, info);
			dst = info->addr + (j * info->size_line + i * 4);
			*(unsigned int *)dst = ((int)(255.999 * colors.x) * 256 * 256) + \
			((int)(255.999 * colors.y) * 256) + (int)(255.999 * colors.z);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

//t_light	light_set(t_point3 light_origin, t_color3 light_amount, double bright_ratio)
//{
//	t_light	new;
//
//	new.origin = light_origin;
//	new.amount = light_amount;
//	new.ratio = bright_ratio;
//	return (new);
//}
//
//void	tmp_init(t_info *info)
//{
//	t_object	*objects;
//	t_light		light;
//
//	objects = object(SPHERE, sphere(point3(2, 0, -5), color3(0, 0, 0.5), 2));
//	obj_add(&objects, object(SPHERE, sphere(point3(-3, 0, -20), color3(0, 0.5, 0), 10)));
//	obj_add(&objects, object(PLANE, plane(point3(0, -3, 0), unit(vec3(-0.4, -1, 0)), color3(1, 1, 0))));
//	obj_add(&objects, object(PLANE, plane(point3(0, -8, 0), unit(vec3(0.3, -1, 0)), color3(0, 1, 0))));
//	obj_add(&objects, object(CYLINDER, cylinder(point3(-1, 2, -4), unit(vec3(-0.4, -1, 1)), color3(1, 0.5, 0), 1, 5)));
//	obj_add(&objects, object(SPHERE, sphere(point3(3, 3, -5), color3(0, 0.5, 0.5), 1)));
//	info->objects = objects;
//
//	light = light_set(point3(0, 10, 0), color3(1, 1, 1), 0.5);
//	info->light = light;
//
//	info->ambient.ratio = 0.3;
//
//	info->ambient.amount = mult_t(color3(1, 1, 1), info->ambient.ratio);
//}

int	red_button(int exitcode, t_info *info)
{
	(void)info;
	exit(exitcode);
}

int main(int argc, char *argv[])
{
	t_info		info;

	ft_memset(&info, 0, sizeof(t_info));
//	tmp_init(&info);
//	mlx_setting(&info);
//	cam_setting(&info.cam);

	if (argc != 2)
		ft_error("wrong number of arguments");

	parse(argv[1], &info);
	draw(&info);
	mlx_hook(info.win, 2, 0, key_press, &info);
	mlx_hook(info.win, 17, 0, red_button, &info);
	mlx_loop(info.mlx);
	return (0);
}


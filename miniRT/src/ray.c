#include "minirt.h"

t_ray	ray_set(t_point3 point, t_vec3 vec)
{
	t_ray new;

	new.origin = point;
	new.dir = unit(vec);
	return (new);
}

t_point3	ray_dest(t_ray ray, double t)
{
	t_point3	dest;

	dest = plus(ray.origin, mult_t(ray.dir, t));
	return (dest);
}

t_ray	ray_primary(t_cam cam, double w, double h)
{
	t_ray ray;

	ray.origin = cam.origin;
	ray.dir = plus(cam.left_bottom, mult_t(cam.dir_hor, w));
	ray.dir = plus(ray.dir, mult_t(cam.dir_ver, h));
	ray.dir = minus(ray.dir, ray.origin);
	ray.dir = unit(ray.dir);
	return (ray);
}

t_color3 ray_color(t_ray ray, t_info *info)
{
	info->rec.t_min = EPSILON;
	info->rec.t_max = INFINITY;
	if (hit(info->objects, ray, &info->rec))
		return (lighting_set(info));
	return (color3(0, 0, 0));
}
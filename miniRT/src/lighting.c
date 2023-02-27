#include "minirt.h"


int	in_shadow(t_object *objects, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.t_min = 0;
	rec.t_max = light_len;
	if (hit(objects, light_ray, &rec))
		return (TRUE);
	return (FALSE);
}

t_color3	get_light_amount(t_info *info, t_light	light)
{
	t_color3	diffuse;
	t_color3	specular;
	t_vec3		light_dir;
	t_vec3		reflect_dir;
	t_vec3		view_dir;
	t_vec3		a;
	t_ray		r_light_ray;
	double		light_len;
	double		similar;
	double		shininess;
	double 		spec_strength;
	double 		diff_strength;
	double		brightness;

	light_dir = minus(light.origin, info->rec.hit_point);
	light_len = vlen(light_dir);
	r_light_ray = ray_set(plus(info->rec.hit_point, mult_t(info->rec.normal_v, EPSILON)), light_dir);
	if (in_shadow(info->objects, r_light_ray, light_len))
		return (color3(0, 0, 0));

	light_dir = unit(light_dir);
	diff_strength = fmax(dot(light_dir, info->rec.normal_v), 0.0);
	diffuse = mult_t(light.amount, diff_strength);

	a = mult_t(info->rec.normal_v, dot(light_dir, info->rec.normal_v));
	reflect_dir = plus(mult_t(light_dir, -1.0), mult_t(a, 2.0));
	view_dir = unit(mult_t(info->ray.dir, -1.0));
	shininess = 64;
	spec_strength = 0.5;
	similar = pow(fmax(dot(reflect_dir, view_dir), 0.0), shininess);
	specular = mult_t(mult_t(light.amount, similar), spec_strength);

	brightness = light.ratio * LUMEN;
	return (mult_t(plus(diffuse, specular), brightness));
}

// hit.h에 있음(임시)
t_color3	lighting_set(t_info *info)
{
	t_color3	light_amount;
	t_light		light;

	light_amount = color3(0, 0, 0);
	light = info->light;

	light_amount = plus(light_amount, get_light_amount(info, light));
	light_amount = plus(light_amount, info->ambient.amount);
	light_amount = color3(light_amount.x * info->rec.rgb.x, \
	light_amount.y * info->rec.rgb.y, \
	light_amount.z * info->rec.rgb.z);
	return(color3(fmin(light_amount.x , 1.0), fmin(light_amount.y , 1.0), fmin(light_amount.z , 1.0)));
}

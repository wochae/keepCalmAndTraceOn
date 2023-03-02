#include "minirt.h"

t_object *object(t_obj_type type, void *element)
{
	t_object	*new;

	if (!(new = malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	return (new);
}

t_sphere *sphere(t_point3 center, t_color3 rgb, double radius)
{
	t_sphere	*new;

	if (!(new = malloc(sizeof(t_sphere))))
		return (NULL);
	new->point = center;
	new->rgb = rgb;
	new->radius = radius;
	new->radius_d = radius * radius;
	return (new);
}

t_plane		*plane(t_point3 center, t_vec3 dir, t_color3 rgb)
{
	t_plane	*new;

	if (!(new = malloc(sizeof(t_plane))))
		return (NULL);
	new->point = center;
	new->dir = dir;
	new->rgb = rgb;
	return (new);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 dir, t_color3 rgb, double radius, double height)
{
	t_cylinder	*new;

	if (!(new = malloc(sizeof(t_cylinder))))
		return (NULL);
	new->point = center;
	new->dir = dir;
	new->rgb = rgb;
	new->radius = radius;
	new->radius_d = radius * radius;
	new->height = height;
	return (new);
}
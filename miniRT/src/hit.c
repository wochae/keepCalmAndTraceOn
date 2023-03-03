/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:17:27 by jiyun             #+#    #+#             */
/*   Updated: 2023/03/03 16:18:24 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_discriminant_sp(t_discriminant *d, t_sphere *sp, t_ray ray)
{
	t_vec3	ray_to_center;

	ray_to_center = minus(ray.origin, sp->point);
	d->a = vlen_d(ray.dir);
	d->b = dot(ray.dir, ray_to_center);
	d->c = vlen_d(ray_to_center) - sp->radius_d;
	d->disc = d->b * d->b - d->a * d->c;
}

void	get_discriminant_cy(t_discriminant *d, t_cylinder *cy, t_ray ray)
{
	t_vec3	ray_to_center;

	ray_to_center = minus(ray.origin, cy->point);
	d->a = vlen_d(cross(ray.dir, cy->dir));
	d->b = dot(cross(ray.dir, cy->dir), cross(ray_to_center, cy->dir));
	d->c = vlen_d(cross(ray_to_center, cy->dir)) - cy->radius_d;
	d->disc = d->b * d->b - d->a * d->c;
}

void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	rec->front_face = dot(ray.dir, rec->normal);
	if (rec->front_face > 0)
		rec->normal = mult_t(rec->normal, -1.0);
}

int	hit_object(t_object *object, t_ray ray, t_hit_record *rec)
{
	int	hit_result;

	hit_result = FALSE;
	if (object->type == SPHERE)
		hit_result = hit_sphere(object, ray, rec);
	if (object->type == PLANE)
		hit_result = hit_plane(object, ray, rec);
	if (object->type == CYLINDER)
		hit_result = hit_cylinder(object, ray, rec);
	return (hit_result);
}

int	hit(t_object *objects, t_ray ray, t_hit_record *rec)
{
	int	hit_result;

	hit_result = FALSE;
	while (objects)
	{
		if (hit_object(objects, ray, rec) != FALSE)
			hit_result = TRUE;
		objects = objects->next;
	}
	return (hit_result);
}

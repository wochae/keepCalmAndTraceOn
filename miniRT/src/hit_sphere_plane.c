/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere_plane.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:17:49 by jiyun             #+#    #+#             */
/*   Updated: 2023/03/03 16:18:15 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hit_sphere(t_object *object, t_ray ray, t_hit_record *rec)
{
	t_sphere		*sphere;
	t_discriminant	d;

	sphere = (t_sphere *)object->element;
	get_discriminant_sp(&d, sphere, ray);
	if (d.disc < 0)
		return (FALSE);
	d.root = (-d.b - sqrt(d.disc)) / d.a;
	if (d.root < rec->t_min || rec->t_max < d.root)
	{
		d.root = (-d.b + sqrt(d.disc)) / d.a;
		if (d.root < rec->t_min || rec->t_max < d.root)
			return (FALSE);
	}
	rec->t = d.root;
	rec->hit_point = ray_dest(ray, d.root);
	rec->normal = devide_t(minus(rec->hit_point, sphere->point), \
	sphere->radius);
	rec->rgb = sphere->rgb;
	set_face_normal(ray, rec);
	rec->t_max = rec->t;
	return (TRUE);
}

int	hit_plane(t_object *object, t_ray ray, t_hit_record *rec)
{
	t_plane	*plane;
	double	numerator;
	double	denominator;
	double	root;

	plane = (t_plane *)object->element;
	denominator = dot(ray.dir, plane->dir);
	if (fabs(denominator) < EPSILON)
		return (FALSE);
	numerator = dot(minus(plane->point, ray.origin), plane->dir);
	root = numerator / denominator;
	if (root < rec->t_min || rec->t_max < root)
		return (FALSE);
	rec->t = root;
	rec->hit_point = ray_dest(ray, root);
	rec->normal = plane->dir;
	rec->rgb = plane->rgb;
	set_face_normal(ray, rec);
	rec->t_max = rec->t;
	return (TRUE);
}

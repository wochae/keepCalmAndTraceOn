/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:08:49 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 17:08:54 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vec3	get_cylin_normal(t_cylinder *cylin, t_point3 hit_point)
{
	double	hit_height;
	t_vec3	hit_height_center;

	hit_height = dot(minus(hit_point, cylin->point), cylin->dir);
	hit_height_center = plus(cylin->point, mult_t(cylin->dir, hit_height));
	return (unit(minus(hit_point, hit_height_center)));
}

int	hit_body(t_cylinder *cylin, t_point3 hit_point)
{
	double	projection;

	projection = dot(minus(hit_point, cylin->point), cylin->dir);
	if (fabs(projection) > cylin->height / 2)
		return (FALSE);
	return (TRUE);
}

int	hit_cylinder_cap(t_object *object, t_ray ray, t_hit_record *rec, double dir)
{
	t_cylinder	*cylin;
	t_point3	center;
	double		numerator;
	double		denominator;
	double		root;

	cylin = (t_cylinder *)object->element;
	center = plus(cylin->point, \
	mult_t(cylin->dir, cylin->height / 2 * dir));
	denominator = dot(ray.dir, cylin->dir);
	if (fabs(denominator) < EPSILON)
		return (FALSE);
	numerator = dot(minus(center, ray.origin), cylin->dir);
	root = numerator / denominator;
	if (root < rec->t_min || rec->t_max < root)
		return (FALSE);
	if (vlen(minus(center, ray_dest(ray, root))) > cylin->radius)
		return (FALSE);
	rec->t = root;
	rec->hit_point = ray_dest(ray, root);
	rec->normal = cylin->dir;
	rec->rgb = cylin->rgb;
	set_face_normal(ray, rec);
	rec->t_max = rec->t;
	return (TRUE);
}

int	hit_cylinder_body(t_object *object, t_ray ray, t_hit_record *rec)
{
	t_cylinder		*cylin;
	t_discriminant	d;

	cylin = (t_cylinder *)object->element;
	get_discriminant_cy(&d, cylin, ray);
	if (d.disc < 0)
		return (FALSE);
	d.root = (-d.b - sqrt(d.disc)) / d.a;
	if (d.root < rec->t_min || rec->t_max < d.root)
	{
		d.root = (-d.b + sqrt(d.disc)) / d.a;
		if (d.root < rec->t_min || rec->t_max < d.root)
			return (FALSE);
	}
	if (!hit_body(cylin, ray_dest(ray, d.root)))
		return (FALSE);
	rec->t = d.root;
	rec->hit_point = ray_dest(ray, d.root);
	rec->normal = get_cylin_normal(cylin, rec->hit_point);
	rec->rgb = cylin->rgb;
	set_face_normal(ray, rec);
	rec->t_max = rec->t;
	return (TRUE);
}

int	hit_cylinder(t_object *object, t_ray ray, t_hit_record *rec)
{
	int	hit_result;

	hit_result = FALSE;
	if (hit_cylinder_body(object, ray, rec))
		hit_result = TRUE;
	if (hit_cylinder_cap(object, ray, rec, 1.0))
		hit_result = TRUE;
	if (hit_cylinder_cap(object, ray, rec, -1.0))
		hit_result = TRUE;
	return (hit_result);
}

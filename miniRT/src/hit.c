#include "minirt.h"

int	hit_object(t_object *object, t_ray ray, t_hit_record *rec)
{
    int hit_result;

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

void	set_face_normal(t_ray ray, t_hit_record *rec)
{
    rec->front_face = dot(ray.dir, rec->normal_v);
    if (rec->front_face > 0)
        rec->normal_v = mult_t(rec->normal_v, -1.0);
}

int	hit_sphere(t_object *object, t_ray ray, t_hit_record *rec)
{
    t_sphere	*sphere;
    t_vec3	ray_to_point;
    double	a;
    double	b;
    double	c;
    double	discriminant;
    double	sqrt_d;
    double	root;
    /* 구의 방정식 x 광선의 방정식 = 판별식 (근의 공식을 활용)
     (O + tD - C)(O + tD - C) = r*r
     t*t*D*D + 2*t*D∙(O - C) + (O - C)∙(O - C) - r*r = 0
     a*t*t + b*t + c = 0
     a = D∙D -> |D||D|, b = 2D∙(O - C), c = (O - C)∙(O - C) - r*r
     discriminant = b*b - 4*a*c

    ray_to_point = minus(ray.origin, sphere.point);
    a = vec3_dot(ray.dir, ray.dir);
    b = 2.0 * vec3_dot(ray_set.dir, ray_to_point);
    c = dot(ray_to_point, ray_to_point) - sphere.radius_d;
    discriminant = b * b - 4 * a * c;
    if (discriminant < 0) // 표면에 스칠 때(dis == 0)는 왜 고려 x?
        return (-1.0);
    else
        return ((-b - sqrt(discriminant)) / (2.0 * a));
     */

    sphere = (t_sphere *)object->element;
    ray_to_point = minus(ray.origin, sphere->point);
    // 짝수 근의 공식 판별식
    a = vlen_d(ray.dir);
    b = dot(ray.dir, ray_to_point);
    c = vlen_d(ray_to_point) - sphere->radius_d;
    discriminant = b * b - a * c;
    if (discriminant < 0)
        return (FALSE);
    sqrt_d = sqrt(discriminant);
    root = (-b - sqrt_d) / a;
    if (root < rec->t_min || rec->t_max < root)
    {
        root = (-b + sqrt_d) / a;
        if (root < rec->t_min || rec->t_max < root)
            return (FALSE);
    }
    rec->t = root;
    rec->hit_point = ray_dest(ray, root);
    rec->normal_v = devide_t(minus(rec->hit_point, sphere->point), sphere->radius);
    rec->rgb = sphere->rgb;
    set_face_normal(ray, rec);
    rec->t_max = rec->t;
    return (TRUE);
}

int hit_plane(t_object *object, t_ray ray, t_hit_record *rec)
{
    t_plane	*plane;
    double	numerator;
    double	denominator;
    double 	root;
    /* 내적 x 광선의 방정식 = 판별식
     (P - P0)∙N = 0
     (O + tD - P0)∙N = 0;
     ~
     t = (P0 - O)∙N / (D∙N)
     */
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
    rec->normal_v = plane->dir; // 평면의 방향이 곧 법선벡터
    rec->rgb = plane->rgb;
    // 광선과 평면이 평행인 상태에서 겹치면?(해가 무한대로 나오면?)
    set_face_normal(ray, rec);
    rec->t_max = rec->t;
    return (TRUE);
}

t_vec3	get_cylin_normal_v(t_cylinder *cylin, t_point3 hit_point)
{
    t_vec3 center;
    double projection = dot(minus(hit_point, cylin->point), cylin->dir);
    center = plus(cylin->point, mult_t(cylin->dir, projection));
//	center = plus(cylin->point, mult_t(cylin->dir, cylin->height)); -> 맞는 곳의
//	center = mult_t(cylin->dir, dot(minus(hit_point, cylin->point), cylin->dir));
//	center = plus(cylin->point, mult_t(cylin->dir, cylin->height));
    return (unit(minus(hit_point, center)));
//	return (devide_t(minus(hit_point, plus(cylin->point, center)), cylin->radius));
}

int hit_body(t_cylinder *cylin, t_point3 hit_point)
{
    double projection;

    projection = dot(minus(hit_point, cylin->point), cylin->dir);
    if (fabs(projection) > cylin->height / 2)
        return (FALSE);
    return (TRUE);
}

int	hit_cylinder_cap(t_object *object, t_ray ray, t_hit_record *rec, double cap_dir)
{
    t_cylinder	*cylin;
    double	numerator;
    double	denominator;
    double 	root;
    /* 내적 x 광선의 방정식 = 판별식
     (P - P0)∙N = 0
     (O + tD - P0)∙N = 0;
     ~
     t = (P0 - O)∙N / (D∙N)
     */
    cylin = (t_cylinder *)object->element;
    t_point3 center = plus(cylin->point, mult_t(cylin->dir, cylin->height / 2 * cap_dir));
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
    rec->normal_v = cylin->dir; // 평면의 방향이 곧 법선벡터
    rec->rgb = cylin->rgb;
    // 광선과 평면이 평행인 상태에서 겹치면?(해가 무한대로 나오면?)
    set_face_normal(ray, rec);
    rec->t_max = rec->t;
    return (TRUE);
}

int	hit_cylinder_body(t_object *object, t_ray ray, t_hit_record *rec)
{
    t_cylinder	*cylin;
//    t_point3	point;
    t_vec3		ray_to_center;
    double	a;
    double	b;
    double	c;
    double	discriminant;
    double	sqrt_d;
    double	root;
    /* 구의 방정식 x 광선의 방정식 = 판별식 (근의 공식을 활용)
     (O + Dt - C) x cy_d = r
     ((O + Dt - C) x cy_d)*((O + Dt - C) x cy_d) = r*r
     (D x cy_d)(D X cy_d)*t*t + 2*(D x cy_d)∙((O - C) x cy_d)*t + ((O - C) x cy_d))((O - C) x cy_d)) = r*r
     a = (D x cy_d)(D X cy_d) -> |D x cy_d||D x cy_d|
     b(half) = (D x cy_d)∙((O - C) x cy_d)
     c = ((O - C) x cy_d))((O - C) x cy_d)) - r*r -> |(O - C) x cy_d)||(O - C) x cy_d)| - r*r
     discriminent = b*b - a*c
     */
    cylin = (t_cylinder *)object->element;
    ray_to_center = minus(ray.origin, cylin->point); // (O - C)
    a = vlen_d(cross(ray.dir, cylin->dir));
    b = dot(cross(ray.dir, cylin->dir), cross(ray_to_center, cylin->dir));
    c = vlen_d(cross(ray_to_center, cylin->dir)) - cylin->radius;
    discriminant = b * b - a * c;
    if (discriminant < 0)
        return (FALSE);
    sqrt_d = sqrt(discriminant);
    root = (-b - sqrt_d) / a;
    if (root < rec->t_min || rec->t_max < root)
    {
        root = (-b + sqrt_d) / a;
        if (root < rec->t_min || rec->t_max < root)
            return (FALSE);
    }
    // the projection of the intersections on the cylinder axis must be <= cylin's height.
    if (!hit_body(cylin, ray_dest(ray, root)))
        return (FALSE);
    rec->t = root;
    rec->hit_point = ray_dest(ray, root);
    rec->normal_v = get_cylin_normal_v(cylin, rec->hit_point);
    rec->rgb = cylin->rgb;
//	set_face_normal(ray, rec);
    rec->t_max = rec->t;
    return (TRUE);
}

int	hit_cylinder(t_object *object, t_ray ray, t_hit_record *rec)
{
    int hit_result;

    hit_result = FALSE;
    if (hit_cylinder_body(object, ray, rec))
        hit_result = TRUE;
    if (hit_cylinder_cap(object, ray, rec, 1.0))
        hit_result = TRUE;
    if (hit_cylinder_cap(object, ray, rec, -1.0))
        hit_result = TRUE;
    return (hit_result);
}
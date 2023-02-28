#ifndef HIT_H
#define HIT_H

# include "minirt.h"

int	hit(t_object *objects, t_ray ray, t_hit_record *rec);
int	hit_sphere(t_object *object, t_ray ray, t_hit_record *rec);
int hit_plane(t_object *object, t_ray ray, t_hit_record *rec);
int	hit_cylinder(t_object *object, t_ray ray, t_hit_record *rec);

t_color3	lighting_set(t_info *info);

#endif

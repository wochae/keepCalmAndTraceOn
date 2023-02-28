#ifndef OBJECT_H
# define OBJECT_H

# include "minirt.h"

t_object	*object(t_obj_type type, void *element);
t_sphere	*sphere(t_point3 point, t_color3 rgb, double radius);
t_plane		*plane(t_point3 point, t_vec3 dir, t_color3 rgb);
t_cylinder  *cylinder(t_point3 point, t_vec3 dir, t_color3 rgb, double diameter, double height);

t_light	    light_set(t_point3 light_origin, t_color3 light_amount, double bright_ratio);

#endif

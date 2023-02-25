#ifndef VECTOR_H
# define VECTOR_H

# include "minirt.h"
# include <math.h>

t_point3	point3(double x, double y, double z);
t_vec3	    vec3(double x, double y, double z);
t_color3	color3(double x, double y, double z);

void	    vec3_set(t_vec3 *vec, double x, double y, double z);
double  	vlen_d(t_vec3 vec);
double	    vlen(t_vec3 vec);
t_vec3	    plus(t_vec3 vec1, t_vec3 vec2);
t_vec3	    minus(t_vec3 vec1, t_vec3 vec2);
double	    dot(t_vec3 vec1, t_vec3 vec2);
t_vec3	    cross(t_vec3 vec1, t_vec3 vec2);
t_vec3	    unit(t_vec3 vec);
t_vec3	    mult(t_vec3 vec1, t_vec3 vec2);
t_vec3	    mult_t(t_vec3 vec, double t);
t_vec3	    devide_t(t_vec3 vec, double t);

#endif

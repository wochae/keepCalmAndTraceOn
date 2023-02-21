#ifndef MINIRT_H
# define MINIRT_H

# include "structures.h"

typedef enum e_obj
{
	SPHERE,
	PLANE,
	CYLINDER,
	CAMERA,
	LIGHT,
}	t_object_type;

typedef enum e_info_type
{
	AMB = 0x0001,
	CAM = 0x0002,
	LIT = 0x0004,
}	t_info_type;


/* parse with ',' */
t_color3	parse_color(char *str);
t_point3	parse_pt(char *str);
t_vec3		parse_n_vec(char *str);

void		mlx_info_init(t_info *info);
t_vec3		cam_set_vup(t_vec3 dir);
void		cam_init(t_info *info);
t_ray		ray_init(t_info *info, double x, double y);


#endif
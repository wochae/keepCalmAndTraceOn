#ifndef MINIRT_H
# define MINIRT_H

# include "structures.h"

// typedef enum e_obj
// {
// 	SPHERE,
// 	PLANE,
// 	CYLINDER,
// 	CAMERA,
// 	LIGHT,
// }	t_object_type;

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

/* parse */
void	check_file_extension(char *file);
void	read_file(char *file, char **content);
void	parse_to_info(char *content, t_info *info);
void	parse_ambient(char **args, t_info *info);
void	parse_camera(char **args, t_info *info);
void	parse_light(char **args, t_info *info);
void	parse_sphere(char **args, t_info *info);
void	parse_plane(char **args, t_info *info);
void	parse_cylinder(char **args, t_info *info);
void	check_n_vec(t_point3 vec);

#endif
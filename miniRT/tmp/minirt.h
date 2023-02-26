#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"

# include "structures.h"
# include "vector.h"
# include "ray.h"
# include "hit.h"

# include "list.h"
# include "object.h"

# define FALSE 0
# define TRUE 1
# define POINT_LIGHT 1
# define EPSILON 1e-6
# define LUMEN 3

/* list */
void            obj_add(t_object **list, t_object *new);

/* init */
t_hit_record	record_init(void);

/* scene */
void	    scene_init(t_info *info);
t_canvas	canvas_set(int w, int h);
void        cam_set(t_info *info);

/* execve */

void	ft_execve(t_info *info);

/* parse with ',' */
t_color3	parse_color(char *str);
t_point3	parse_pt(char *str);
t_vec3		parse_n_vec(char *str);

void		mlx_info_init(t_info *info);
t_vec3		cam_set_vup(t_vec3 dir);
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

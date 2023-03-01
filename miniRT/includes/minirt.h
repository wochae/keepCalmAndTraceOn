#ifndef MINIRT_H
# define MINIRT_H

# include "structures.h"

# define WIDTH	1200
# define HEIGHT	800
# define TRUE 1
# define FALSE 0

# define MOVEMENT 0.1
# define ROTATION 0.1
# define EPSILON 1e-6
# define LUMEN 3


/* init */
t_hit_record	record_init(void);
t_canvas        canvas_set(int w, int h);
void            cam_setting(t_info *info);
void            scene_init(t_info *info);
void            mlx_setting(t_info *info);


/* execve */
void	draw(t_info *info);

/* parse with ',' */
t_color3	parse_color(char *str);
t_point3	parse_pt(char *str);
t_vec3		parse_n_vec(char *str);

void		mlx_info_init(t_info *info);
t_vec3		cam_set_vup(t_vec3 dir);
t_ray		ray_init(t_info *info, double x, double y);


/* vector */

t_point3	point3(double x, double y, double z);
t_vec3	vec3(double x, double y, double z);
t_color3	color3(double x, double y, double z);

void	vset(t_vec3 *vec, double x, double y, double z);
double	vlen_d(t_vec3 vec);
double	vlen(t_vec3 vec);
t_vec3	plus(t_vec3 vec1, t_vec3 vec2);
t_vec3	minus(t_vec3 vec1, t_vec3 vec2);
double	dot(t_vec3 vec1, t_vec3 vec2);
t_vec3	cross(t_vec3 vec1, t_vec3 vec2);
t_vec3	unit(t_vec3 vec);
t_vec3	mult(t_vec3 vec1, t_vec3 vec2);
t_vec3	mult_t(t_vec3 vec, double t);
t_vec3	devide_t(t_vec3 vec, double t);

/* object */

void	    obj_add(t_object **list, t_object *new);
t_object	*object(t_obj_type type, void *element);
t_sphere	*sphere(t_point3 point, t_color3 rgb, double radius);
t_plane		*plane(t_point3 point, t_vec3 dir, t_color3 rgb);
t_cylinder  *cylinder(t_point3 point, t_vec3 dir, t_color3 rgb, double diameter, double height);

t_light	    light_set(t_point3 light_origin, t_color3 light_amount, double bright_ratio);

/* ray */
t_ray		ray_set(t_point3 point, t_vec3 vec);
t_point3	ray_dest(t_ray ray, double t);
t_ray		ray_primary(t_info *info, double horiz, double verti);
t_color3    ray_color(t_ray ray, t_info *info);

/* hit */

int	hit(t_object *objects, t_ray ray, t_hit_record *rec);
int	hit_sphere(t_object *object, t_ray ray, t_hit_record *rec);
int hit_plane(t_object *object, t_ray ray, t_hit_record *rec);
int	hit_cylinder(t_object *object, t_ray ray, t_hit_record *rec);
t_color3	lighting_set(t_info *info);


/* key valid */
int		is_move_key(int keycode);
int		is_rotate_key(int keycode);
int		key_press(int keycode, t_info *info);
void	print_key_info(t_info *info);
void	key_move(void *clicked, int type, t_vec3 dir, int keycode);
void	key_rotate(void *clicked, int type, int keycode);

/* move objects */

void	move_obj(t_point3 *point, t_vec3 dir);
void	move_camera(t_cam *cam, int keycode);
void	move_light(t_light *light, t_vec3 dir, int keycode);
void	move_sphere(t_sphere *sphere, t_vec3 dir, int keycode);
void	move_plane(t_plane *plane, t_vec3 dir, int keycode);
void	move_cylinder(t_cylinder *cylinder, t_vec3 dir, int keycode);

/* rotate objects */

void	rotate_obj(t_vec3 *dir, t_vec3 rot);
void	rotate_camera(t_cam *cam, int keycode);
void	rotate_plane(t_plane *pl, int keycode);
void	rotate_cylinder(t_cylinder *cy, int keycode);

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


void	reverse_color(t_object *obj);

#endif

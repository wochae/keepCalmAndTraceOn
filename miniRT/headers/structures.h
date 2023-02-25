#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "libft.h"
# include "minirt.h"

# define FALSE 0
# define TRUE 1
# define POINT_LIGHT 1
# define EPSILON 1e-6
# define LUMEN 3

typedef enum e_obj_type
{
	AMB = 0x0001,
	CAM = 0x0002,
	LIT = 0x0004,
	SPHERE = 0x0008,
	PLANE = 0x0009,
	CYLINDER = 0x000a
}	t_obj_type;

struct s_dot3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_dot3	t_point3;
typedef struct s_dot3	t_vec3;
typedef struct s_dot3	t_color3;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		dir;
}	t_ray;

typedef struct s_cam
{
	t_point3	origin;
	t_vec3		looking_side;
	t_vec3		dir_horizontal;
	t_vec3		dir_vertical;
	double		viewport_w;
	double		viewport_h;
	double		focal_len;
	double		fov;
	t_point3	left_bottom;
}	t_cam;

typedef struct s_canvas
{
	int			canvas_w;
	int			canvas_h;
	double		ratio;
}	t_canvas;

typedef struct s_object
{
	t_obj_type	type;
	void		*element;
	void		*next;
}	t_object;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius_d;
	t_color3	sp_rgb;
}	t_sphere;

typedef struct s_plane
{
	t_point3	pos;
	t_vec3		dir;
	t_color3	color;
}	t_plane;

typedef struct s_cylinder
{
	t_point3	pos;
	t_vec3		dir;
	t_color3	color;
	double		r;
	double		height;
}	t_cylinder;

typedef struct s_hit_record
{
	t_point3	hit_point;
	t_vec3		normal_v;
	double		t;
	double		t_min; // t가 음수면 광선이 뒤를 향하는 것 = 카메라 뒤에 있는 것
	double 		t_max; // 너무 멀 경우
	double		front_face;
	t_color3	rgb;
}	t_hit_record;

typedef struct s_light
{
	t_point3	origin;
	t_color3	amount;
	double		bright_ratio;
}	t_light;

typedef struct s_ambient
{
	t_color3	amount;
	double		ratio;
}	t_ambient;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int 			size_line;
	int 			endian;
	t_canvas		canvas;
	t_cam			cam;
	t_object		*objects; //object->element에 오브젝트를 통째로 담아야됨! 즉, object->element가 오브젝트 연결리스트임
	t_light         light;
	t_ambient		ambient;
	t_ray			ray;
	t_hit_record	rec;

// void clicked;
// int clicked_type;
// 
}	t_info;

#endif
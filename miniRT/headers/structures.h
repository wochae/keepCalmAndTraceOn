#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "libft.h"

typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;
typedef int					t_bool;
# define FALSE 0
# define TRUE 1

typedef int					t_object_type;
# define SP 0
# define LIGHT_POINT 1

# define EPSILON 1e-6
# define LUMEN 3

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_ambient
{
	t_color3	color;
	double		ratio;
}	t_ambient;


typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	t_bool		front_face;
	double		tmin;
	double		tmax;
	double		t;
	t_color3	albedo;
}	t_hit_record;

typedef struct s_camera
{
	t_point3		orig;
	t_point3		left_bottom;
	t_vec3			horizontal;
	t_vec3			vertical;
	double			viewport_w;
	double			viewport_h;
	double			focal_len;
}	t_camera;

typedef struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
}	t_canvas;

typedef struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_ray			ray;
	t_hit_record	rec;
}	t_scene;

// 오브젝트 구조체
typedef struct s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
}	t_object;

typedef struct s_light
{
	t_point3		origin;
	t_color3		light_color;
	double			bright_ratio;
}	t_light;

typedef struct s_sphere
{
	t_point3	center;
	t_color3	color;
	double		radius;
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

typedef struct s_obj
{
	int				type;
	void			*obj_info;
}	t_obj;

typedef struct s_hit_check
{
	t_point3	pos;
	t_vec3		n_vec;
	t_color3	albedo;
	double		t;
	double		t_min;
	double		t_max;
}	t_hit_check;

typedef struct s_ray
{
	t_point3	orig;
	t_vec3		dir;
}	t_ray;

typedef struct s_pong
{
	t_vec3		lig_dir;
	t_vec3		view_dir;
	t_vec3		ref_dir;
	t_vec3		dif;
	t_vec3		specular;
	double		spec;
	double		ks;
	double		ksn;
	double		kd;
	double		lig_len;
}	t_pong;

typedef struct s_info
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*addr;
	int					bpp;
	int					size_line;
	int					endian;
	struct s_ambient	amb;
	t_camera			cam;
	struct s_light		light;
	void				*clicked;
	int					clicked_type;
	t_list				*objs;
}	t_info;

#endif

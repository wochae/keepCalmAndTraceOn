#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "libft.h"

# define FALSE 0
# define TRUE 1
# define POINT_LIGHT 1
# define EPSILON 1e-6
// define LUMEN 3 SPEC 0

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

//typedef struct s_mlx
//{
//	void	*mlx;
//	void	*win;
//	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int 	size_line;
//	int 	endian;
//}	t_mlx;

struct s_dot3
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_dot3 t_point3;
typedef struct s_dot3 t_vec3;
typedef struct s_dot3 t_color3;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		dir_v;
}	t_ray;

typedef struct s_cam
{
	t_point3	origin;
//	double		viewport_w;
//	double		viewport_h;
//	t_vec3		dir_horizontal;
//	t_vec3		dir_vertical;
//	double		focal_len;
	t_vec3		looking_side;
	double		fov;
//	t_point3	left_bottom;
}	t_cam;

typedef struct s_object
{
	t_obj_type	type;
	void		*element;
	void		*next;
	t_color3	albedo;
}	t_object;

typedef struct s_sphere
{
	t_point3	center;
	double		radius; //->diameter을 반으로 나눠서
	double 		radius_d;
	t_color3    sp_rgb;
}	t_sphere;

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
//	void	*mlx;
//	void	*win;
//	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int 	size_line;
//	int 	endian;
//	t_canvas		canvas; // wht using for?
	t_cam			cam;
	t_object		*objects; //object->element에 오브젝트를 통째로 담아야됨! 즉, object->element가 오브젝트 연결리스트임
	t_light         light;
	t_ambient		ambient;
	t_ray			ray;
//	t_hit_record	rec;

// void clicked;
// int clicked_type;
// 
}	t_info;

#endif
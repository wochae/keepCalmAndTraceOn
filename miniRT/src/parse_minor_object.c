#include "minirt.h"

void    parse_sphere(char **args, t_info *info)
{
	t_object	*obj;
	t_sphere	*new_sp;

	if (ft_strslen(args) != 4)
		ft_error("wrong input : 'sp' must have 4 arguments");
	obj = (t_object *)malloc(sizeof(t_object));
	new_sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!obj || !new_sp)
		ft_error("malloc failed");
	new_sp->center = parse_pt(args[1]);
	new_sp->radius = ft_atod(args[2]) / 2;
	new_sp->radius_d = new_sp->radius * new_sp->radius;
	new_sp->sp_rgb = parse_pt(args[3]);
	obj->element = new_sp;
	obj->type = SPHERE;
	obj_add(info->objects, obj);
}

void	parse_plane(char **args, t_info *info)
{
	t_object	*obj;
	t_plane		*new_pl;

	if (ft_strslen(args) != 4)
		ft_error("wrong input : 'pl' must have 4 arguments");
	obj = (t_object *)malloc(sizeof(t_object));
	new_pl = (t_plane *)malloc(sizeof(t_plane));
	if (!obj || !new_pl)
		ft_error("memory allocation failed");
	new_pl->pos = parse_pt(args[1]);
	new_pl->dir = parse_pt(args[2]);
	check_n_vec(new_pl->dir);
	new_pl->color = parse_color(args[3]);
	obj->element = new_pl;
	obj->type = PLANE;
	obj_add(info->objects, obj);
}

void	parse_cylinder(char **args, t_info *info)
{
	t_object	*obj;
	t_cylinder	*new_cy;

	if (ft_strslen(args) != 6)
		ft_error("wrong input : 'cy' must have 6 arguments");
	obj = (t_object *)malloc(sizeof(t_object));
	new_cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!obj || !new_cy)
		ft_error("memory allocation failed");
	new_cy->pos = parse_pt(args[1]);
	new_cy->dir = parse_pt(args[2]);
	check_n_vec(new_cy->dir);
	new_cy->r = ft_atod(args[3]) / 2;
	new_cy->height = ft_atod(args[4]);
	new_cy->color = parse_color(args[5]);
	obj->type = CYLINDER;
	obj->element = new_cy;
	obj_add(info->objects, obj);
}
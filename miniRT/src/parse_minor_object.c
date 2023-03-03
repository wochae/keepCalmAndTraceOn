/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_minor_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:19:47 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 16:20:45 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(char **args, t_info *info)
{
	t_object	*obj;
	t_sphere	*new_sp;

	if (ft_strslen(args) != 4)
		ft_error("wrong input : 'sp' must have 4 arguments");
	obj = (t_object *)malloc(sizeof(t_object));
	new_sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!obj || !new_sp)
		ft_error("malloc failed");
	new_sp->point = parse_pt(args[1]);
	new_sp->radius = ft_atod(args[2]) / 2;
	new_sp->radius_d = (new_sp->radius) * (new_sp->radius);
	new_sp->rgb = parse_color(args[3]);
	obj->element = new_sp;
	obj->type = SPHERE;
	obj->next = NULL;
	obj_add(&info->objects, obj);
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
	new_pl->point = parse_pt(args[1]);
	new_pl->dir = unit(parse_n_vec(args[2]));
	new_pl->rgb = parse_color(args[3]);
	obj->element = new_pl;
	obj->type = PLANE;
	obj->next = NULL;
	obj_add(&info->objects, obj);
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
	new_cy->point = parse_pt(args[1]);
	new_cy->dir = unit(parse_n_vec(args[2]));
	new_cy->radius = ft_atod(args[3]) / 2;
	new_cy->radius_d = (new_cy->radius) * (new_cy->radius);
	new_cy->height = ft_atod(args[4]);
	new_cy->rgb = parse_color(args[5]);
	obj->type = CYLINDER;
	obj->element = new_cy;
	obj->next = NULL;
	obj_add(&info->objects, obj);
}

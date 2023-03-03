/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:28:42 by jiyun             #+#    #+#             */
/*   Updated: 2023/03/03 16:51:15 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	key_move(void *clicked, int type, t_vec3 dir, int keycode)
{
	if (type == PLANE)
		move_plane((t_plane *)((t_object *)clicked)->element, dir, keycode);
	if (type == SPHERE)
		move_sphere((t_sphere *)((t_object *)clicked)->element, dir, keycode);
	if (type == CYLINDER)
		move_cylinder((t_cylinder *)((t_object *)clicked)->element, \
				dir, keycode);
	if (type == LIGHT)
		move_light((t_light *)clicked, dir, keycode);
	if (type == CAMERA)
		move_camera((t_cam *)clicked, keycode);
}

int	is_move_key(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || \
			keycode == KEY_D || keycode == KEY_Q || keycode == KEY_E)
		return (TRUE);
	return (FALSE);
}

void	move_obj(t_point3 *point, t_vec3 dir)
{
	*point = plus(*point, dir);
}

void	reverse_color(t_object *obj)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;

	if (obj == NULL)
		return ;
	if (obj->type == SPHERE)
	{
		sphere = (t_sphere *)obj->element;
		sphere->rgb = (t_point3){1 - sphere->rgb.x, \
			1 - sphere->rgb.y, 1 - sphere->rgb.z};
	}
	else if (obj->type == PLANE)
	{
		plane = (t_plane *)obj->element;
		plane->rgb = (t_point3){1 - plane->rgb.x, \
			1 - plane->rgb.y, 1 - plane->rgb.z};
	}
	else if (obj->type == CYLINDER)
	{
		cylinder = (t_cylinder *)obj->element;
		cylinder->rgb = (t_point3){1 - cylinder->rgb.x, \
			1 - cylinder->rgb.y, 1 - cylinder->rgb.z};
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rotate_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:32:03 by jiyun             #+#    #+#             */
/*   Updated: 2023/03/03 16:33:26 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotate_obj(t_vec3 *dir, t_vec3 rot)
{
	t_vec3	tmp;

	tmp = (t_vec3){dir->x, dir->y, dir->z};
	if (rot.x)
	{
		dir->y = tmp.y * cos(rot.x) - tmp.z * sin(rot.x);
		dir->z = tmp.y * sin(rot.x) + tmp.z * cos(rot.x);
	}
	if (rot.y)
	{
		dir->x = tmp.x * cos(rot.y) - tmp.z * sin(rot.y);
		dir->z = tmp.x * sin(rot.y) + tmp.z * cos(rot.y);
	}
	if (rot.z)
	{
		dir->x = tmp.x * cos(rot.z) - tmp.y * sin(rot.z);
		dir->y = tmp.x * sin(rot.z) + tmp.y * cos(rot.z);
	}
	*dir = unit(*dir);
}

int	is_rotate_key(int keycode)
{
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT || \
		keycode == KEY_UP || keycode == KEY_DOWN || \
		keycode == KEY_COMMA || keycode == KEY_DOT)
		return (TRUE);
	return (FALSE);
}

void	key_rotate(void *clicked, int type, int keycode)
{
	if (type == PLANE)
		rotate_plane((t_plane *)((t_object *)clicked)->element, keycode);
	if (type == CYLINDER)
		rotate_cylinder((t_cylinder *)((t_object *)clicked)->element, keycode);
	if (type == CAMERA)
		rotate_camera((t_cam *)clicked, keycode);
}

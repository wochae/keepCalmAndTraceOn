/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:09:19 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 17:09:23 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	move_camera(t_cam *cam, int keycode)
{
	t_vec3	dir;
	t_vec3	back;
	t_vec3	right;
	t_vec3	up;

	dir = cam->dir;
	back = mult_t(dir, -1);
	right = unit(cross(cam_set_vup(dir), back));
	up = unit(cross(back, right));
	if (keycode == KEY_W)
		move_obj(&cam->origin, mult_t(dir, MOVEMENT));
	if (keycode == KEY_S)
		move_obj(&cam->origin, mult_t(dir, -MOVEMENT));
	if (keycode == KEY_D)
		move_obj(&cam->origin, mult_t(right, MOVEMENT));
	if (keycode == KEY_A)
		move_obj(&cam->origin, mult_t(right, -MOVEMENT));
	if (keycode == KEY_E)
		move_obj(&cam->origin, mult_t(up, MOVEMENT));
	if (keycode == KEY_Q)
		move_obj(&cam->origin, mult_t(up, -MOVEMENT));
}

void	move_light(t_light *light, t_vec3 dir, int keycode)
{
	t_vec3	back;
	t_vec3	right;
	t_vec3	up;

	back = mult_t(dir, -1);
	right = unit(cross(cam_set_vup(dir), back));
	up = unit(cross(back, right));
	if (keycode == KEY_W)
		move_obj(&light->origin, mult_t(dir, MOVEMENT));
	if (keycode == KEY_S)
		move_obj(&light->origin, mult_t(dir, -MOVEMENT));
	if (keycode == KEY_D)
		move_obj(&light->origin, mult_t(right, MOVEMENT));
	if (keycode == KEY_A)
		move_obj(&light->origin, mult_t(right, -MOVEMENT));
	if (keycode == KEY_E)
		move_obj(&light->origin, mult_t(up, MOVEMENT));
	if (keycode == KEY_Q)
		move_obj(&light->origin, mult_t(up, -MOVEMENT));
}

void	move_sphere(t_sphere *sphere, t_vec3 dir, int keycode)
{
	t_vec3	back;
	t_vec3	right;
	t_vec3	up;

	back = mult_t(dir, -1);
	right = unit(cross(cam_set_vup(dir), back));
	up = unit(cross(back, right));
	if (keycode == KEY_W)
		move_obj(&sphere->point, mult_t(dir, MOVEMENT));
	if (keycode == KEY_S)
		move_obj(&sphere->point, mult_t(dir, -MOVEMENT));
	if (keycode == KEY_D)
		move_obj(&sphere->point, mult_t(right, MOVEMENT));
	if (keycode == KEY_A)
		move_obj(&sphere->point, mult_t(right, -MOVEMENT));
	if (keycode == KEY_E)
		move_obj(&sphere->point, mult_t(up, MOVEMENT));
	if (keycode == KEY_Q)
		move_obj(&sphere->point, mult_t(up, -MOVEMENT));
}

void	move_plane(t_plane *plane, t_vec3 dir, int keycode)
{
	t_vec3	back;
	t_vec3	right;
	t_vec3	up;

	back = mult_t(dir, -1);
	right = unit(cross(cam_set_vup(dir), back));
	up = unit(cross(back, right));
	if (keycode == KEY_W)
		move_obj(&plane->point, mult_t(dir, MOVEMENT));
	if (keycode == KEY_S)
		move_obj(&plane->point, mult_t(dir, -MOVEMENT));
	if (keycode == KEY_D)
		move_obj(&plane->point, mult_t(right, MOVEMENT));
	if (keycode == KEY_A)
		move_obj(&plane->point, mult_t(right, -MOVEMENT));
	if (keycode == KEY_E)
		move_obj(&plane->point, mult_t(up, MOVEMENT));
	if (keycode == KEY_Q)
		move_obj(&plane->point, mult_t(up, -MOVEMENT));
}

void	move_cylinder(t_cylinder *cylinder, t_vec3 dir, int keycode)
{
	t_vec3	back;
	t_vec3	right;
	t_vec3	up;

	back = mult_t(dir, -1);
	right = unit(cross(cam_set_vup(dir), back));
	up = unit(cross(back, right));
	if (keycode == KEY_W)
		move_obj(&cylinder->point, mult_t(dir, MOVEMENT));
	if (keycode == KEY_S)
		move_obj(&cylinder->point, mult_t(dir, -MOVEMENT));
	if (keycode == KEY_D)
		move_obj(&cylinder->point, mult_t(right, MOVEMENT));
	if (keycode == KEY_A)
		move_obj(&cylinder->point, mult_t(right, -MOVEMENT));
	if (keycode == KEY_E)
		move_obj(&cylinder->point, mult_t(up, MOVEMENT));
	if (keycode == KEY_Q)
		move_obj(&cylinder->point, mult_t(up, -MOVEMENT));
}

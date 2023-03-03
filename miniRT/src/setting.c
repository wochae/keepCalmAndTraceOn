/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:03:56 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 17:03:58 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_setting(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		ft_error("mlx_init() failed");
	if (!info->win)
		info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "test");
	if (!info->img)
		info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->addr)
		info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel, \
		&info->size_line, &info->endian);
}

t_vec3	cam_set_vup(t_vec3 dir)
{
	if (dir.x == 0 && dir.y != 0 && dir.z == 0)
		return (vec3(0, dir.y, 1e-6));
	else
		return (vec3(0, 1, 0));
}

void	cam_setting(t_cam *cam)
{
	t_vec3	opposite;
	t_vec3	hor;
	t_vec3	ver;

	cam->focal_len = tan((cam->fov * M_PI / 180.0) / 2.0);
	cam->viewport_h = 2.0 * cam->focal_len;
	cam->viewport_w = cam->viewport_h * (double)WIDTH / (double)HEIGHT;
	opposite = mult_t(cam->dir, -1);
	hor = unit(cross(cam_set_vup(cam->dir), opposite));
	ver = cross(opposite, hor);
	cam->dir_hor = mult_t(hor, cam->viewport_w);
	cam->dir_ver = mult_t(ver, cam->viewport_h);
	cam->left_bottom = minus(minus(minus(cam->origin, \
		devide_t(cam->dir_hor, 2)), devide_t(cam->dir_ver, 2)), opposite);
}

void	free_objects(t_info *info)
{
	t_object	*lst;
	t_object	*to_del;

	lst = info->objects;
	if (!lst)
		return ;
	while (lst)
	{
		to_del = lst;
		lst = lst->next;
		free(to_del->element);
		free(to_del);
		to_del = NULL;
	}
}

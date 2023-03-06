/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:05:34 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 17:05:43 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_point3	point3(double x, double y, double z)
{
	t_point3	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_color3	color3(double x, double y, double z)
{
	t_color3	color;

	color.x = x;
	color.y = y;
	color.z = z;
	return (color);
}

t_vec3	mult_t(t_vec3 vec, double t)
{
	t_vec3	new;

	new.x = vec.x * t;
	new.y = vec.y * t;
	new.z = vec.z * t;
	return (new);
}

t_vec3	devide_t(t_vec3 vec, double t)
{
	t_vec3	new;

	new.x = vec.x / t;
	new.y = vec.y / t;
	new.z = vec.z / t;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:00:10 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 17:05:21 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	dot(t_vec3 vec1, t_vec3 vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

t_vec3	cross(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	normal;

	normal.x = vec1.y * vec2.z - vec1.z * vec2.y;
	normal.y = vec1.z * vec2.x - vec1.x * vec2.z;
	normal.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (normal);
}

t_vec3	unit(t_vec3 vec)
{
	t_vec3	new;
	double	len;

	len = vlen(vec);
	if (len == 0)
		ft_error("Vector length is 0\n");
	new.x = vec.x / len;
	new.y = vec.y / len;
	new.z = vec.z / len;
	return (new);
}

t_vec3	mult(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	new;

	new.x = vec1.x * vec2.x;
	new.y = vec1.y * vec2.y;
	new.z = vec1.z * vec2.z;
	return (new);
}

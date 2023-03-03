/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyun <jiyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:27:48 by jiyun             #+#    #+#             */
/*   Updated: 2023/03/03 17:27:59 by jiyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BONUS_H
# define VECTOR_BONUS_H

# include "structures_bonus.h"

t_point3	point3(double x, double y, double z);
t_vec3		vec3(double x, double y, double z);
t_color3	color3(double x, double y, double z);

double		vlen_d(t_vec3 vec);
double		vlen(t_vec3 vec);
t_vec3		plus(t_vec3 vec1, t_vec3 vec2);
t_vec3		minus(t_vec3 vec1, t_vec3 vec2);
double		dot(t_vec3 vec1, t_vec3 vec2);
t_vec3		cross(t_vec3 vec1, t_vec3 vec2);
t_vec3		unit(t_vec3 vec);
t_vec3		mult(t_vec3 vec1, t_vec3 vec2);
t_vec3		mult_t(t_vec3 vec, double t);
t_vec3		devide_t(t_vec3 vec, double t);

#endif

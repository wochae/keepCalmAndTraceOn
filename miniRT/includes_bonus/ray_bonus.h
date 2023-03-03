/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:26:49 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 17:26:57 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_BONUS_H
# define RAY_BONUS_H

# include "structures_bonus.h"

t_ray		ray_set(t_point3 point, t_vec3 vec);
t_point3	ray_dest(t_ray ray, double t);
t_ray		ray_primary(t_cam cam, double w, double h);
t_color3	ray_color(t_ray ray, t_info *info);

t_color3	lighting_set(t_info *info);

#endif

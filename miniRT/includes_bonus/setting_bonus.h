/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:18:05 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 17:27:00 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_BONUS_H
# define SETTING_BONUS_H

# include "structures_bonus.h"

void	mlx_setting(t_info *info);
t_vec3	cam_set_vup(t_vec3 dir);
void	cam_setting(t_cam *cam);
void	free_objects(t_info *info);

#endif

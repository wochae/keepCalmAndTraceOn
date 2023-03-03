/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:25:56 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 17:26:30 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include "structures_bonus.h"

void		obj_add(t_object **list, t_object *new);

t_color3	parse_color(char *str);
t_point3	parse_pt(char *str);
t_point3	parse_n_vec(char *str);

void		parse_ambient(char **args, t_info *info);
void		parse_camera(char **args, t_info *info);
void		parse_light(char **args, t_info *info);
void		parse_sphere(char **args, t_info *info);
void		parse_plane(char **args, t_info *info);
void		parse_cylinder(char **args, t_info *info);
void		check_file_extension(char *file);
void		read_file(char *file, char **content);
void		parse_to_info(char *content, t_info *info);

#endif
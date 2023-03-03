/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:56:44 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 16:56:52 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MAP_BONUS_H
# define KEY_MAP_BONUS_H

# include "structures_bonus.h"

# define MOVEMENT 0.1
# define ROTATION 0.1

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14

# define KEY_DELETE 51
# define KEY_ESC 53
# define KEY_L 37
# define KEY_C 8
# define KEY_O 31

# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 125
# define KEY_DOWN 126
# define KEY_COMMA 43
# define KEY_DOT 47

/* key valid */
int		is_move_key(int keycode);
int		is_rotate_key(int keycode);
int		key_press(int keycode, t_info *info);
void	print_key_info(t_info *info);
void	key_move(void *clicked, int type, t_vec3 dir, int keycode);
void	key_rotate(void *clicked, int type, int keycode);

/* move objects */
void	move_obj(t_point3 *point, t_vec3 dir);
void	move_camera(t_cam *cam, int keycode);
void	move_light(t_light *light, t_vec3 dir, int keycode);
void	move_sphere(t_sphere *sphere, t_vec3 dir, int keycode);
void	move_plane(t_plane *plane, t_vec3 dir, int keycode);
void	move_cylinder(t_cylinder *cylinder, t_vec3 dir, int keycode);

/* rotate objects */
void	rotate_obj(t_vec3 *dir, t_vec3 rot);
void	rotate_camera(t_cam *cam, int keycode);
void	rotate_plane(t_plane *pl, int keycode);
void	rotate_cylinder(t_cylinder *cy, int keycode);

/* overall */
void	reverse_color(t_object *obj);

#endif
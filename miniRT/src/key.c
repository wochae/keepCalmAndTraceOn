#include "minirt.h"

int	is_valid_key(int keycode)
{
    if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || \
		keycode == KEY_D || keycode == KEY_LEFT || keycode == KEY_RIGHT || \
		keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_ESC || \
        keycode == KEY_Q || keycode == KEY_E || keycode == KEY_O || \
		keycode == KEY_L || keycode == KEY_C || keycode == KEY_DELETE || \
		keycode == 43 || keycode == 47)
        return (TRUE);
    return (FALSE);
}

void	select_object_by_key(t_info *info, int keycode)
{
    if (keycode == KEY_L)
    {
        if (info->clicked && (info->clicked_type == SPHERE || \
			info->clicked_type == PLANE || info->clicked_type == CYLINDER))
            reverse_color(info->clicked);
        info->clicked = &info->light;
        info->clicked_type = LIGHT;
    }
    else if (keycode == KEY_C)
    {
        if (info->clicked && (info->clicked_type == SPHERE || \
			info->clicked_type == PLANE || info->clicked_type == CYLINDER))
            reverse_color(info->clicked);
        info->clicked = &info->cam;
        info->clicked_type = CAMERA;
    }
    else if (keycode == KEY_O)
    {
        t_object *object = (t_object *)info->clicked;
        if (info->clicked && (info->clicked_type == SPHERE || \
			info->clicked_type == PLANE || info->clicked_type == CYLINDER))
            reverse_color(info->clicked);
		if (object && info->clicked_type != CAMERA && info->clicked_type != LIGHT && object->next)
        	info->clicked = object->next;
		else
			info->clicked = info->objects;
        info->clicked_type = ((t_object *)info->clicked)->type;
		reverse_color(info->clicked);
	}
}

void	print_key_info(t_info *info)
{
    mlx_string_put(info->mlx, info->win, 20, HEIGHT + 40, 0xFFFFFF, \
		"W : move forward");
    mlx_string_put(info->mlx, info->win, 170, HEIGHT + 40, 0xFFFFFF, \
		"S : move backward");
    mlx_string_put(info->mlx, info->win, 20, HEIGHT + 60, 0xFFFFFF, \
		"D : move right");
    mlx_string_put(info->mlx, info->win, 170, HEIGHT + 60, 0xFFFFFF, \
		"A : move left");
    mlx_string_put(info->mlx, info->win, 20, HEIGHT + 80, 0xFFFFFF, \
		"Q : move up");
    mlx_string_put(info->mlx, info->win, 170, HEIGHT + 80, 0xFFFFFF, \
		"E : move down");
    mlx_string_put(info->mlx, info->win, 320, HEIGHT + 40, 0xFFFFFF, \
		"< : rotate left from x_axis");
    mlx_string_put(info->mlx, info->win, 520, HEIGHT + 40, 0xFFFFFF, \
		"> : rotate right from x_axis");
    mlx_string_put(info->mlx, info->win, 320, HEIGHT + 60, 0xFFFFFF, \
		"^ : rotate left from y_axis");
    mlx_string_put(info->mlx, info->win, 520, HEIGHT + 60, 0xFFFFFF, \
		"v : rotate right from y_axis");
    mlx_string_put(info->mlx, info->win, 320, HEIGHT + 80, 0xFFFFFF, \
		"Light pos");
}

void	reverse_color(t_object *obj)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;

	if (obj == NULL)
		return ;
	if (obj->type == SPHERE)
	{
		sphere = (t_sphere *)obj->element;
		sphere->rgb = (t_point3){1 - sphere->rgb.x, \
			1 - sphere->rgb.y, 1 - sphere->rgb.z};
	}
	else if (obj->type == PLANE)
	{
		plane = (t_plane *)obj->element;
		plane->rgb = (t_point3){1 - plane->rgb.x, \
			1 - plane->rgb.y, 1 - plane->rgb.z};
	}
	else if (obj->type == CYLINDER)
	{
		cylinder = (t_cylinder *)obj->element;
		cylinder->rgb = (t_point3){1 - cylinder->rgb.x, \
			1 - cylinder->rgb.y, 1 - cylinder->rgb.z};
	}
}

int	key_press(int keycode, t_info *info)
{
	if (!is_valid_key(keycode))
		return (0);
	if (keycode == KEY_ESC)
		exit(0);
	select_object_by_key(info, keycode);
	if (!info->clicked)
		return (0);
	if (keycode == KEY_DELETE && info->clicked && \
	info->clicked_type != CAMERA && info->clicked_type != LIGHT)
	{
		reverse_color(info->clicked);
		info->clicked = NULL;
	}
	else if (is_rotate_key(keycode))
		key_rotate(info->clicked, info->clicked_type, keycode);
	else if (is_move_key(keycode))
		key_move(info->clicked, info->clicked_type, info->cam.dir, keycode);
	cam_setting(&info->cam);
	draw(info);
	return (0);
}

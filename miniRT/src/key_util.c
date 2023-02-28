#include "minirt.h"
#include "key_map.h"
#include "../mlx/mlx.h"

int	is_valid_key(int keycode)
{
    if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || \
		keycode == KEY_D || keycode == KEY_LEFT || keycode == KEY_RIGHT || \
		keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_ESC || \
        keycode == KEY_Q || keycode == KEY_E || \
		keycode == KEY_L || keycode == KEY_C || keycode == KEY_DELETE)
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
        info->clicked_type = LIT;
    }
    else if (keycode == KEY_C)
    {
        if (info->clicked && (info->clicked_type == SPHERE || \
			info->clicked_type == PLANE || info->clicked_type == CYLINDER))
            reverse_color(info->clicked);
        info->clicked = &info->cam;
        info->clicked_type = CAM;
    }
    else if (keycode == KEY_O)
    {
        t_object *object = (t_object *)info->clicked;
        if (object->next)
        if (info->clicked && (info->clicked_type == SPHERE || \
			info->clicked_type == PLANE || info->clicked_type == CYLINDER))
            reverse_color(info->clicked);
        info->clicked = &info->objects->element;
        info->clicked_type = OBJ;
    }
        return ;
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
		"^ : rotate left from x_axis");
    mlx_string_put(info->mlx, info->win, 520, HEIGHT + 40, 0xFFFFFF, \
		"v : rotate right from x_axis");
    mlx_string_put(info->mlx, info->win, 320, HEIGHT + 60, 0xFFFFFF, \
		"< : rotate left from y_axis");
    mlx_string_put(info->mlx, info->win, 520, HEIGHT + 60, 0xFFFFFF, \
		"> : rotate right from y_axis");
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
    if (keycode == KEY_DELETE && info->clicked)
    {
        reverse_color(info->clicked);
        info->clicked = NULL;
    }
    else if (is_rotate_key(keycode))
        key_rotate(info->clicked, info->clicked_type, keycode);
    else if (is_move_key(keycode))
        key_move(info->clicked, info->clicked_type, info->cam.dir, keycode);
    draw(info);
    return (0);
}
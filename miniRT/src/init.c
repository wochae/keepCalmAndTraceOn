#include "../includes/minirt.h"
#include <math.h>


t_vec3	cam_set_vup(t_vec3 dir)
{
	if (dir.x == 0 && dir.y != 0 && dir.z == 0)
		return (vec3(0, dir.y, 1e-6));
	else
		return (vec3(0, 1, 0));
}

void	scene_init(t_info *info)
{
	info->canvas = canvas_set(960, 540);
	cam_setting(info);
}


void	cam_setting(t_info *info) // 원래 이름 cam_init
{
	t_vec3	w;
	t_vec3	u;
	t_vec3	v;

	info->cam.focal_len = tan((info->cam.fov * M_PI / 180.0) / 2.0);
	info->cam.viewport_h = 2.0 * info->cam.focal_len;
	info->cam.viewport_w = info->cam.viewport_h * (double)WIDTH / (double)HEIGHT;
	w = mult_t(info->cam.dir, -1);
	u = unit(cross(cam_set_vup(info->cam.dir), w));
	v = cross(w, u);
	info->cam.dir_horizontal = mult_t(u, info->cam.viewport_w);
	info->cam.dir_vertical = mult_t(v, info->cam.viewport_h);
	info->cam.left_bottom = minus(minus(minus(info->cam.origin, \
		devide_t(info->cam.dir_horizontal, 2)), devide_t(info->cam.dir_vertical, 2)), w);
}

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.t_min = EPSILON;
	record.t_max = INFINITY;
	return (record);
}

t_canvas	canvas_set(int w, int h)
{
	t_canvas	canvas;

	canvas.canvas_w = w;
	canvas.canvas_h = h;
	canvas.ratio = (double)w / (double)h;
	return (canvas);
}

// void	cam_setting(t_info *info)
// {
//     t_cam cam = info->cam;
//     double	viewport_w;
//     double	viewport_h;

//     double h = tan(cam.fov / 2);
//     cam.viewport_h = 2.0 * h;
//     cam.viewport_w = viewport_h * info->canvas.ratio;
//     cam.focal_len = tan((info->cam.fov * M_PI / 180.0) / 2.0);
//     cam.dir_horizontal = vec3(cam.viewport_w, 0, 0);
//     cam.dir_vertical = vec3(0, cam.viewport_h, 0);
//     cam.left_bottom = minus(cam.origin, vec3(0, 0, cam.focal_len));
//     cam.left_bottom = minus(cam.left_bottom, devide_t(cam.dir_vertical, 2));
//     cam.left_bottom = minus(cam.left_bottom, devide_t(cam.dir_horizontal, 2));
//     info->cam = cam;
// }
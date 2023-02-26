#include "minirt.h"
#include <math.h>

void	scene_init(t_info *info)
{
	info->canvas = canvas_set(960, 540);
	cam_set(info);
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

void	cam_set(t_info *info)
{
	t_cam	cam;

    cam = info->cam;
	cam.focal_len = tan(cam.fov/2);
	cam.viewport_h = 2.0 * cam.focal_len;
	cam.viewport_w = cam.viewport_h * info->canvas.ratio;
    cam.dir_horizontal = vec3(cam.viewport_w, 0, 0);
    cam.dir_vertical = vec3(0, cam.viewport_h, 0);
	cam.left_bottom = minus(cam.origin, vec3(0, 0, cam.focal_len));
	cam.left_bottom = minus(cam.left_bottom, devide_t(cam.dir_vertical, 2));
	cam.left_bottom = minus(cam.left_bottom, devide_t(cam.dir_horizontal, 2));
	info->cam = cam;
}
#include "scene.h"
#include "vector.h"
#include <math.h>

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
	info->cam.looking_side = unit(info->cam.looking_side);
	info->cam.focal_len = tan((info->cam.fov * M_PI / 180.0) / 2.0);
	info->cam.viewport_h = 2.0 * info->cam.focal_len;
	info->cam.viewport_w = cam.viewport_h * info->canvas.ratio;
	cam.left_bottom = minus(cam.origin, vec3(0, 0, cam.focal_len));
	cam.left_bottom = minus(cam.left_bottom, devide_t(cam.dir_vertical, 2));
	cam.left_bottom = minus(cam.left_bottom, devide_t(cam.dir_horizontal, 2));
	info->cam = cam;
}
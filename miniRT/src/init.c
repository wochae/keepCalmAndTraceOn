#include "minirt.h"

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
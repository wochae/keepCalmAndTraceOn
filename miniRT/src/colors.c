#include "../includes/minirt.h"

void	reverse_color(t_object *obj)
{
    t_sphere    *sp;
    t_plane     *pl;
    t_cylinder  *cy;

    if (obj->type == SPHERE)
    {
        sp = (t_sphere *)obj->element;
        sp->rgb = (t_color3){1 - sp->rgb.x, \
			1 - sp->rgb.y, 1 - sp->rgb.z};
    }
    else if (obj->type == PLANE)
    {
        pl = (t_plane *)obj->element;
        pl->rgb = (t_color3){1 - pl->rgb.x, \
			1 - pl->rgb.y, 1 - pl->rgb.z};
    }
    else if (obj->type == CYLINDER)
    {
        cy = (t_cylinder *)obj->element;
        cy->rgb = (t_color3){1 - cy->rgb.x, \
			1 - cy->rgb.y, 1 - cy->rgb.z};
    }
}

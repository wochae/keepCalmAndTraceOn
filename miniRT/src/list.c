#include "../includes/minirt.h"

void    obj_add(t_object **list, t_object *new)
{
    t_object    *cur;

    if (*list == NULL)
    {
        *list = new;
        return ;
    }
    cur = *list;
    while (cur->next)
        cur = cur->next;
    cur->next = new;
}
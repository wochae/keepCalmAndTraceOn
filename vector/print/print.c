#include "print.h"

void    write_color(t_color3 pixel_color)
{
    printf("%d %d %d\n", (int)(255.999 * pixel_color.x), (int)(255.999 * pixel_color.y), (int)(255.999 * pixel_color.z));
}
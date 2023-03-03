#include "minirt.h"
void    ft_error(char *msg)
{
    ft_putstr_fd(RED, 2);
    ft_putendl_fd("Error", 2);
    ft_putstr_fd(YELLOW, 2);
    ft_putendl_fd(msg, 2);
    exit(1);
}
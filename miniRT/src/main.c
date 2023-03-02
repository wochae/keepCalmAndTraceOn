#include "minirt.h"

static void	parse(char *argv, t_info *info)
{
    char	*content;

    content = ft_strdup("");
    if (!content)
        ft_error("memory alloc failed");
    check_file_extension(argv);
    read_file(argv, &content);
    parse_to_info(content, info);
    mlx_setting(info);
    cam_setting(&info->cam);
}

void draw(t_info *info)
{
    int			i;
    int 		j;
    char		*dst;
    t_color3	colors;

    j = 0;
    while (j < HEIGHT)
    {
        i = 0;
        while (i < WIDTH)
        {
            info->ray = ray_primary(info->cam, \
			(double)i / (WIDTH - 1), \
			(HEIGHT - 1 - (double)j) / (HEIGHT - 1));
            colors = ray_color(info->ray, info);
            dst = info->addr + (j * info->size_line + i * 4);
            *(unsigned int *)dst = ((int)(255.999 * colors.x) * 256 * 256) + \
			((int)(255.999 * colors.y) * 256) + (int)(255.999 * colors.z);
            i++;
        }
        j++;
    }
    mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

int	red_button(int exitcode, t_info *info)
{
    mlx_destroy_window(info->mlx, info->win);
    exit(exitcode);
}

int main(int argc, char *argv[])
{
    t_info		info;

    ft_memset(&info, 0, sizeof(t_info));

    if (argc != 2)
        ft_error("wrong number of arguments");

    parse(argv[1], &info);
    draw(&info);
    mlx_hook(info.win, 2, 0, key_press, &info);
    mlx_hook(info.win, 17, 0, red_button, &info);
    mlx_loop(info.mlx);
    return (0);
}


#include "../includes/minirt.h"
#include "../mlx/mlx.h"

static void	parse(char *argv, t_info *info)
{
    char	*content;

    content = ft_strdup("");
    if (!content)
        ft_error("memory alloc failed");
    check_file_extension(argv);
    read_file(argv, &content);
    parse_to_info(content, info);
    scene_init(info);

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
            *(unsigned int *)dst = ((int)(255.999 * colors.x) * 256 * 256) + ((int)(255.999 * colors.y) * 256) + (int)(255.999 * colors.z);
            i++;
        }
        j++;
    }
    mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

static int	red_button(t_info *info)
{
    mlx_destroy_window(info->mlx, info->win);
    exit(0);
}


static void    ft_execve(t_info *info)
{
    mlx_setting(info);
    draw(info);
    mlx_hook(info->win, 2, 0, key_press, info);
    mlx_hook(info->win, 17, 0, red_button, info);
    mlx_loop(info->mlx);
}

void	mlx_setting(t_info *info)
{
    info->mlx = mlx_init();
	if (!info->mlx)
		ft_error("mlx_init() failed");
    info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "test1");
    if (!info->win)
		ft_error("mlx_new_window() failed");
	info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->img)
		ft_error("mlx_new_image() failed");
	info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel, \
		&info->size_line, &info->endian);
	if (!info->addr)
		ft_error("mlx_get_data_addr() failed");
    print_key_info(info);
    mlx_string_put(info->mlx, info->win, 20, HEIGHT + 20, 0xFFFFFF, \
		"C : select camera");
    mlx_string_put(info->mlx, info->win, 170, HEIGHT + 20, 0xFFFFFF, \
		"L : select light");
}

int main(int argc, char **argv)
{
    t_info		info;

	ft_memset(&info, 0, sizeof(t_info));
	if (argc != 2)
		ft_error("wrong number of arguments");
    parse(argv[1], &info);
    // render with ray_set
    ft_execve(&info);
    exit(0);
}


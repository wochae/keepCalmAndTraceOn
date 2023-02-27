#include "../tmp/minirt.h"

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
    mlx_setting(info); // -> 이거 parse() 안 어딘가에 넣으면 좋을듯

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

void	mlx_setting(t_info *info)
{
    info->mlx = mlx_init();
    info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "test");
    info->img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
    info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->size_line, &info->endian);
}

int main(int argc, char **argv)
{
    t_info		*info;

    if (!(info = malloc(sizeof(t_info))))
        return (0);
	ft_memset(&info, 0, sizeof(t_info));
	if (argc != 2)
		ft_error("wrong number of arguments");
    parse(argv[1], info);
    // render with ray_set
    draw(info);
    // mlx_hook
    mlx_loop(info->mlx);
    return (0);
}


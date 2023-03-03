/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochae <wochae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:10:31 by wochae            #+#    #+#             */
/*   Updated: 2023/03/03 17:10:33 by wochae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

static void	parse(char *argv, t_info *info)
{
	char	*content;

	mlx_setting(info);
	content = ft_strdup("");
	if (!content)
		ft_error("memory alloc failed");
	check_file_extension(argv);
	read_file(argv, &content);
	parse_to_info(content, info);
	cam_setting(&info->cam);
}

void	put_pixel(t_info *info, t_color3 colors, int i, int j)
{
	char	*dst;
	int		r;
	int		g;
	int		b;

	dst = info->addr + ((j * info->size_line) + (i * 4));
	r = 255.999 * colors.x;
	g = 255.999 * colors.y;
	b = 255.999 * colors.z;
	*(unsigned int *)dst = (r * 256 * 256) + (g * 256) + b;
}

void	draw(t_info *info)
{
	int			i;
	int			j;
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
			put_pixel(info, colors, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}

int	red_button(int exitcode, t_info *info)
{
	free_objects(info);
	if (info->mlx && info->win)
		mlx_destroy_window(info->mlx, info->win);
	exit(exitcode);
}

int	main(int argc, char *argv[])
{
	t_info	info;

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

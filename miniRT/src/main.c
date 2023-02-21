#include "minirt.h"
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
}

static void	ft_execute(t_info *info)
{

}

int	main(int argc, char *argv)
{
	t_info	info;

	ft_memset(&info, 0, sizeof(t_info));
	if (argc != 2)
		ft_error("wrong number of arguments");
	parse(argv[1], &info);
	ft_execve(&info);
	exit(0);
}
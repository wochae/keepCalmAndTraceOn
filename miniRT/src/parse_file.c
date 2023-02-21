#include "minirt.h"
#include <fcntl.h>

#define BUFFER_SIZE 1024

void	check_file_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 3 || ft_strcmp(&file[len - 3], ".rt"))
		ft_error("wrong file extension");
}

void	read_file(char *file, char **content)
{
	int		fd;
	int		read_size;
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("can't open file");
	while (1)
	{
		ft_memset(buf, 0, BUFFER_SIZE);
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size < 0)
			ft_error("malloc has been filed");
		if (read_size < BUFFER_SIZE)
			break ;
	}
	close(fd);
}

static void	parse_a_line(char *line, int *flag, t_info *info)
{
	char	**args;

	args = ft_split(line, ' ');
	if (!args)
		ft_error("alloc failed");
	check_duplicate_info(args[0], flag);
	if (!ft_strcmp(args[0], "A"))
		parse_ambient(args, info);
	else if (!ft_strcmp(args[0], "C"))
		parse_camera(args, info);
	else if (!ft_strcmp(args[0], "L"))
		parse_light(args, info);
	else if (!ft_strcmp(args[0], "sp"))
		parse_sphere(args, info);
	else if (!ft_strcmp(args[0], "pl"))
		parse_plane(args, info);
	else if (!ft_strcmp(args[0], "cy"))
		parse_cylinder(args, info);
	else
		ft_error("wrong input : undefined identifier");
	ft_free_strs(args);
}

void	parse_to_info(char *content, t_info *info)
{
	int		i;
	int		flag;
	char	**lines;

	i = -1;
	flag = 0;
	lines = ft_split(content, "\n");
	if (!lines)
		ft_error("alloc failed");
	free(content);
	while (lines[++i])
		parse_a_line(lines[i], &flag, info);
	
}
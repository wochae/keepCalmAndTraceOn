#include "minirt.h"
#include <fcntl.h>

#define BUFFER_SIZE 1024

void	check_file_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len <= 3 || ft_strcmp(&file[len - 3], ".rt"))
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
			break ;
		buf[read_size] = 0;
		tmp = *content;
		*content = ft_strjoin(*content, buf);
		free(tmp);
		if (!content)
			ft_error("memory allocating failed");
		if (read_size < BUFFER_SIZE)
			break ;
	}
	ft_putstr_fd("read file good\n", 2);
	close(fd);
}

static void check_dup_info(char *key, int *flag)
{
	if (!ft_strcmp(key, "A") && *flag & AMB)
		ft_error("'A' should be only one");
	if (!ft_strcmp(key, "C") && *flag & CAM)
		ft_error("'C' should be only one");
	if (!ft_strcmp(key, "L") && *flag & LIT)
		ft_error("'L' should be only one");
	if (!ft_strcmp(key, "A"))
		*flag |= AMB;
	if (!ft_strcmp(key, "C"))
		*flag |= CAM;
	if (!ft_strcmp(key, "L"))
		*flag |= LIT;
	ft_putstr_fd("dup check good?\n", 2);
}

static void	parse_a_line(char *line, int *flag, t_info *info)
{
	char	**args;

	args = ft_split(line, ' ');
	if (!args)
		ft_error("alloc failed");
	check_dup_info(args[0], flag);
	if (!ft_strcmp(args[0], "A"))
		parse_ambient(args, info);
	else if (!ft_strcmp(args[0], "C"))
		parse_camera(args, info);
	else if (!ft_strcmp(args[0], "L"))
		parse_light(args, info);
	// else if (!ft_strcmp(args[0], "sp"))
	// 	parse_sphere(args, info);
	// else if (!ft_strcmp(args[0], "pl"))
	// 	parse_plane(args, info);
	// else if (!ft_strcmp(args[0], "cy"))
	// 	parse_cylinder(args, info);
	else
		ft_error("wrong input : undefined identifier");
	ft_putstr_fd("flag passed\n", 2);
	ft_free_strs(args);
}

void	parse_to_info(char *content, t_info *info)
{
	int		i;
	int		flag;
	char	**lines;

	i = -1;
	flag = 0;
	lines = ft_split(content, '\n');
	if (!lines)
		ft_error("alloc failed");
	free(content);
	while (lines[++i])
		parse_a_line(lines[i], &flag, info);
	ft_free_strs(lines);
	int v = (flag ^ AMB ^ CAM ^ LIT);
	ft_putnbr_fd(flag, 2);
	ft_putnbr_fd(AMB, 2);
	ft_putnbr_fd(CAM, 2);
	ft_putnbr_fd(LIT, 2);
	ft_putnbr_fd(v, 2);
	ft_putendl_fd("", 2);
	
	// if (flag ^ AMB ^ CAM ^ LIT)
	// 	ft_error("The major factors (A, C, L) are not sufficient.");	
}
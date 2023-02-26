NAME = miniRT

CFILES = main.c \
		ray.c \
		vector.c \
		lighting.c \
		init.c \
		parse_file.c \
		parse_major_object.c \
		parse_minor_object.c \
		parse_util.c \
		list.c \
		hit.c \
		object.c

SRC_DIR = ./src
HDRS = ./tmp

SRCS = ${addprefix ${SRC_DIR}/, ${CFILES}}
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -O2
MLX_FLAGS	=	-L./mlx -lmlx -framework OpenGL -framework Appkit
LIBFT = libft/libft.a

all : $(NAME)

%.o : %.c
	gcc $(CFLAGS) -c -o $@ $< -I $(HDRS) -g


$(NAME) :$(OBJS)
	make -C libft
	make -C mlx
	cc $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean :
	make clean -C libft
	make clean -C mlx
	rm -f $(OBJS) $(BONUS_OBJS)

fclean :
	make clean
	rm -f $(LIBFT)
	rm -f $(NAME) $(BONUS)

re :
	make fclean
	make all

.PHONY : clean fclean re all

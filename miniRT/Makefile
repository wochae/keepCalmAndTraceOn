NAME = miniRT
BONUS = miniRT_bonus
CFILES = 
BONUS_CFILES = 

SRC_DIR = ./src

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
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : clean fclean re all
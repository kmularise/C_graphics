CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = error_handler_sub.c\
    error_handler_sub2.c\
    error_handler_sub2.c\
    error_handler_utils.c\
    error_handler.c\
	event_handler.c\
    event_handler2.c\
    ft_split.c\
    game_utils.c\
    game.c\
    get_next_line_utils.c\
    get_next_line.c\
    ft_printf_utils.c\
    ft_printf.c\
    ft_printf_type_1.c\
    ft_printf_type_2.c\
    main.c

NAME = so_long
OBJS = ${SRCS:.c=.o}

all : make_mlx ${NAME}

make_mlx:
	make -C mlx all

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit $^ ./mlx/libmlx.a -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make -C mlx clean
	rm -rf $(OBJS)

fclean : clean
	make -C mlx clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re
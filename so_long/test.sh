#cc -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit error_handler.c
#cc -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit main.c
#cc -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit program_exit_test2.c
norm ./*.c
#./a.out
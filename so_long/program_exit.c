#include "mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int program_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int do_event(int keycode, t_vars *vars)//ESC : 53
{
	if (keycode == KEY_ESC)
		return (program_exit(vars));
	if (keycode == KEY_W)
		return (printf("key_hook...%d\n", keycode));
	if (keycode == KEY_A)
		return (printf("key_hook...%d\n", keycode));
	if (keycode == KEY_D)
		return (printf("key_hook...%d\n", keycode));
	if (keycode == KEY_S)
		return (printf("key_hook...%d\n", keycode));
	
	printf("key_hook...other %d\n", keycode);
	// mlx_destroy_window(vars->mlx, vars->win);
	// exit(0);
	return (0);
}


int	key_hook(int keycode, int *p_cnt)
{
	printf("key_hook...%d\n", keycode);
	*p_cnt +=1;
	return (0);
}


int main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	
	// int cnt = 0;
	// mlx_key_hook(vars.win, &key_hook, &cnt);
	mlx_hook(vars.win, 2, 1L<<0, do_event, &vars);//KEY를 누르면 꺼짐.
	mlx_loop(vars.mlx);
}

// #include <mlx.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
// 	mlx_loop(vars.mlx);
// }
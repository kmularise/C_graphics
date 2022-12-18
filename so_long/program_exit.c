#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int close(int keycode, t_vars *vars)//ESC : 53
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
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
	
	int cnt = 0;
	//mlx_key_hook(vars.win, &key_hook, &cnt);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);//KEY를 누르면 꺼짐.
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
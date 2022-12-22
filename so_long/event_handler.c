#include "so_long.h"
//event handle 할 때는 구조체 한개에 담는 것이 좋음
// 처리하기

int program_exit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		return (program_exit(game));
	if (keycode == KEY_W)
		return (move_up(game));
	if (keycode == KEY_D)
		return (move_right(game));
	if (keycode == KEY_A)
		return (move_left(game));
	if (keycode == KEY_S)
		return (move_right(game));
	
}

//event_handler 
int	event_handle(t_game *game, t_position *pos)
{
	mlx_hook(game->win, KEY_PRESS, 0, key_press, &pos);
	
}

#include "so_long.h"

// #include "error_handler_sub.c"
// #include "error_handler.c"
// #include "error_handler_sub2.c"
// #include "error_handler_utils.c"
// #include "get_next_line.c"
// #include "get_next_line_utils.c"
// #include "ft_split.c"
// #include "game.c"
// #include "game_utils.c"
// #include "event_handler.c"
// #include "event_handler2.c"
// #include "ft_printf.c"
// # include "ft_printf_type_1.c"
// # include "ft_printf_type_2.c"
// # include "ft_printf_utils.c"

void show_error(char *error_message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_message);
	exit(0);
}

int main (int argc, char *argv[])
{
	if (argc != 2)
		show_error("invalid input parameter count!");
	char **map =read_map(argv[1]);
	if (!map)
		show_error("invalid file or empty file!");
	check_map_valid(map);
	t_info *board = get_map_component_count(map);
	check_component_count_valid(board);
	t_info *player = set_player(board);
	check_map_connected(player, board);
	t_game *game = set_game(player);
	game->mlx = mlx_init();
	start(game);
	system("leaks a.out");
}
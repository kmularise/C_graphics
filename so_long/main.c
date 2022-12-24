/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:21:07 by yuikim            #+#    #+#             */
/*   Updated: 2022/12/24 15:56:02 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_error(char *error_message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error_message);
	exit(0);
}

int	has_right_ext(char *filename)
{
	const int	len = ft_strlen(filename);

	if (filename[len - 1] != 'r')
		return (0);
	if (filename[len - 2] != 'e')
		return (0);
	if (filename[len - 3] != 'b')
		return (0);
	if (filename[len - 4] != '.')
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	char	**map;
	t_info	*board;
	t_info	*player;
	t_game	*game;

	if (argc != 2)
		show_error("Invalid input parameter count!");
	if (!has_right_ext(argv[1]))
		show_error("Invalid file extension!");
	map = read_map(argv[1]);
	if (!map)
		show_error("Invalid file or empty file!");
	check_map_valid(map);
	board = get_map_component_count(map);
	check_component_count_valid(board);
	player = set_player(board);
	check_map_connected(player, board);
	game = set_game(player);
	game->mlx = mlx_init();
	start(game);
}

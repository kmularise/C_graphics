/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:06:55 by yuikim            #+#    #+#             */
/*   Updated: 2022/12/24 15:07:21 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_info	*get_map_component_count(char **map)
{
	t_info	*board;
	int		y;
	int		x;

	board = init_info(map);
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
				board->total_c_count++;
			if (map[y][x] == 'E')
				board->total_e_count++;
			if (map[y][x] == 'P')
			{
				board->y = y;
				board->x = x;
				board->total_p_count++;
			}
		}
	}
	return (board);
}

void	check_component_count_valid(t_info *board)
{
	if (!is_component_count_valid(board))
		show_error("count is not valid");
}

void	check_map_valid(char **map)
{
	if (!is_map_valid_width(map))
		show_error("width is not valid");
	if (!is_map_component_valid(map))
		show_error("component is not valid");
}

void	check_map_connected(t_info *player, t_info *board)
{
	if (!is_map_connected(player, board))
		show_error("You can't get all collectives!");
}

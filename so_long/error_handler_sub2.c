/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_sub2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:05:45 by yuikim            #+#    #+#             */
/*   Updated: 2022/12/24 15:05:53 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_info	*set_player(t_info *board)
{
	t_info	*player;

	player = init_info(board->map);
	player->x = board->x;
	player->y = board->y;
	return (player);
}

int	dfs(int x, int y, t_info *player, char **visited)
{
	if (x <= -1 || x >= player->width || y <= -1 || y >= player->height)
		return (0);
	if ((player->map)[y][x] == '1')
		return (0);
	if (visited[y][x] == '0')
	{
		visited[y][x] = '1';
		if ((player->map)[y][x] == 'E')
			(player->total_e_count)++;
		if ((player->map)[y][x] == 'C')
			(player->total_c_count)++;
		dfs(x - 1, y, player, visited);
		dfs(x, y - 1, player, visited);
		dfs(x + 1, y, player, visited);
		dfs(x, y + 1, player, visited);
		return (1);
	}
	return (0);
}

int	is_map_connected(t_info *player, t_info *board)
{
	char	**visited;

	visited = make_2dim_zero(board->height, board->width);
	dfs(player->x, player->y, player, visited);
	ft_free_d_ptr(visited);
	if (player->total_c_count != board->total_c_count)
		return (0);
	if (player->total_e_count != 1)
		return (0);
	return (1);
}

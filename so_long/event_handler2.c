/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:13:01 by yuikim            #+#    #+#             */
/*   Updated: 2022/12/24 15:13:47 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(int next_y, int next_x, t_game *game)
{
	game->p_y = next_y;
	game->p_x = next_x;
	game->move++;
	ft_printf("move count : %d\n", game->move);
}

void	get_collective(t_game *game)
{
	game->c_count++;
	game->map[game->p_y][game->p_x] = '0';
}

void	check_game_end(t_game *game)
{
	if (game->c_count == game->total_c_count)
	{
		ft_printf("game end!!");
		exit(0);
	}
}

char	*get_image_path(int keycode)
{
	if (keycode == KEY_W)
		return (PLAYER_BACK);
	if (keycode == KEY_D)
		return (PLAYER_RIGHT);
	if (keycode == KEY_A)
		return (PLAYER_LEFT);
	return (PLAYER_FRONT);
}

int	check_valid_move(int next_y, int next_x, t_game *game, int keycode)
{
	char	*path;

	path = get_image_path(keycode);
	if (game->map[next_y][next_x] == '1')
		return (-1);
	move(next_y, next_x, game);
	if (game->map[next_y][next_x] == 'C')
		get_collective(game);
	put_background_image(game);
	put_component_image(game);
	put_player_image(game, path);
	if (game->map[next_y][next_x] == 'E')
		check_game_end(game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:11:56 by yuikim            #+#    #+#             */
/*   Updated: 2022/12/24 15:11:57 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(void)
{
	ft_printf("click red cross.. program exit");
	exit(0);
	return (0);
}

int	program_exit(t_game *game)
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
		return (check_valid_move(game->p_y - 1, game->p_x, game, KEY_W));
	if (keycode == KEY_S)
		return (check_valid_move(game->p_y + 1, game->p_x, game, KEY_S));
	if (keycode == KEY_D)
		return (check_valid_move(game->p_y, game->p_x + 1, game, KEY_D));
	if (keycode == KEY_A)
		return (check_valid_move(game->p_y, game->p_x - 1, game, KEY_A));
	ft_printf("please press valid key\n");
	return (0);
}

int	event_handle(t_game *game)
{
	mlx_hook(game->win, KEY_PRESS, 0, key_press, game);
	mlx_hook(game->win, KEY_EXIT, 0, exit_hook, game);
	return (0);
}

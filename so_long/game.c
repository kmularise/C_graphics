/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:15:03 by yuikim            #+#    #+#             */
/*   Updated: 2022/12/24 15:26:41 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*set_game(t_info *player)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->move = 0;
	game->c_count = 0;
	game->total_c_count = player->total_c_count;
	game->map = player->map;
	game->p_y = player->y;
	game->p_x = player->x;
	return (game);
}

int	put_background_image(t_game *game)
{
	int	y;
	int	x;
	int	img_width;
	int	img_height;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			game->img = mlx_xpm_file_to_image(game->mlx,
					"./images/floor.xpm", &img_width, &img_height);
			mlx_put_image_to_window(game->mlx, game->win,
				game->img, x * UNIT_PIXEL, y * UNIT_PIXEL);
			x++;
		}
		y++;
	}
	return (0);
}

int	put_player_image(t_game *game, char *path)
{
	int		img_width;
	int		img_height;

	game->img = mlx_xpm_file_to_image(game->mlx,
			path, &img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->win,
		game->img, (game->p_x) * UNIT_PIXEL, (game->p_y) * UNIT_PIXEL);
	return (0);
}

int	put_component_image(t_game *game)
{
	int		y;
	int		x;
	int		img_width;
	int		img_height;
	char	*path;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '0' && game->map[y][x] != 'P')
			{
				path = get_xpm_path(game->map[y][x]);
				game->img = mlx_xpm_file_to_image(game->mlx,
						path, &img_width, &img_height);
				mlx_put_image_to_window(game->mlx, game->win,
					game->img, x * UNIT_PIXEL, y * UNIT_PIXEL);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	start(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, UNIT_PIXEL * ft_strlen(game->map[0]),
			UNIT_PIXEL * ft_get_height(game->map), "so_long");
	put_background_image(game);
	put_player_image(game, PLAYER_FRONT);
	put_component_image(game);
	event_handle(game);
	mlx_loop(game->mlx);
}

#include "so_long.h"

int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, UNIT_PIXEL * (game->width),
			UNIT_PIXEL *(game->height), "so_long");
	return (0);
}

int	put_background_image(t_game *game)
{
	int	y;
	int	x;
	int	img_width;
	int	img_height;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
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

char	*get_xpm_path(char component)
{
	if (component == 'P')
		return ("./images/character_front.xpm");
	if (component == '1')
		return ("./images/wall.xpm");
	if (component == 'E')
		return ("./images/exit.xpm");
	if (component == 'C')
		return ("./images/tomato.xpm");
	return ("./images/floor.xpm");
}

int	put_component_image(t_game *game)
{
	int		y;
	int		x;
	int		img_width;
	int		img_height;
	char	*path;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] != '0')
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
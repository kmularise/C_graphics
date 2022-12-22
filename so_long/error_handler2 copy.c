#include "so_long.h"

t_info	*get_player_info(char **map)
{
	t_info	*player;
	int		y;
	int		x;

	player = malloc(sizeof(t_info));
	y = 0;
	player->total_c_count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				player->y = y;
				player->x = x;
			}
			if (map[y][x] == 'C')
				player->total_c_count += 1;
			x++;
		}
		y++;
	}
}

char	**make_2dim_zero(int height, int width)
{
	char	**result;
	char	temp;
	int		i;
	int		j;

	temp = '0';
	result = malloc(sizeof(char *) * (height + 1));
	i = 0;
	while (i < height)
	{
		j = 0;
		result[i] = malloc(sizeof(char) * (width + 1));
		while (j < width)
		{
			result[i][j] = temp;
			j++;
		}
		result[i][j] = 0;
		i++;
	}
	result[i] = NULL;
	return (result);
}

int	dfs(int x, int y, t_info *game, char **visited)
{
	if (x <= -1 || x >= game->width || y <= -1 || y >= game->height)
		return (0);
	if ((game->map)[y][x] == '1')
		return (0);
	if (visited[y][x] == '0')
	{
		visited[y][x] = '1';
		if ((game->map)[y][x] == 'E')
			(game->total_e_count)++;
		if ((game->map)[y][x] == 'C')
			(game->total_c_count)++;
		dfs(x - 1, y, game, visited);
		dfs(x, y - 1, game, visited);
		dfs(x + 1, y, game, visited);
		dfs(x, y + 1, game, visited);
		return (1);
	}
	return (0);
}

void ft_free_d_ptr(char **double_ptr)
{
	int	i;

	i = 0;
	while (double_ptr[i])
	{
		free(double_ptr[i]);
		i++;
	}
	free(double_ptr);
}

void	ft_free_game(t_game *game)
{
	if (game->mlx)
		free(game->mlx);
	if (game->win)
		free(game->win);
	if (game->img)
		free(game->img);
	if (game->map)
		ft_free_d_ptr(game->map);
}

int	is_map_connected(t_game *game, t_position *player_pos)
{
	char		**visited;

	//player_pos = get_player_info(game);
	visited = make_2dim_zero(game->height, game->width);
	game->e_count = 0;
	game->c_count = 0;
	dfs(player_pos->x, player_pos->y, game, visited);
	ft_free_d_ptr(visited);
	if (player_pos->c_count != game->c_count)
		return (0);
	if (game->e_count == 0)
		return (0);
	return (1);
}
#include "so_long.h"

t_position	*get_player_info(t_game *game)
{
	t_position	*pos;
	int			y;
	int			x;

	pos = malloc(sizeof(t_position));
	y = 0;
	pos->c_count = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				pos->y = y;
				pos->x = x;
			}
			if (game->map[y][x] == 'C')
				pos->c_count += 1;
			x++;
		}
		y++;
	}
	return (pos);
}

char	**make_2din_zero(int height, int width)
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

int	dfs(int x, int y, t_game *game, char **visited)
{
	if (x <= -1 || x >= game->width || y <= -1 || y >= game->height)
		return (0);
	if ((game->map)[y][x] == '1')
		return (0);
	if (visited[y][x] == '0')
	{
		visited[y][x] = '1';
		if ((game->map)[y][x] == 'E')
			(game->e_count)++;
		if ((game->map)[y][x] == 'C')
			(game->c_count)++;
		dfs(x - 1, y, game, visited);
		dfs(x, y - 1, game, visited);
		dfs(x + 1, y, game, visited);
		dfs(x, y + 1, game, visited);
		return (1);
	}
	return (0);
}

int is_map_connected(t_game *game)
{
	t_position	*player_pos;
	char		**visited;

	player_pos = get_player_info(game);
	visited = make_2din_zero(game->height, game->width);
	game->e_count = 0;
	game->c_count = 0;
	dfs(player_pos->x, player_pos->y, game, visited);
	if (player_pos->c_count != game->c_count)
		return (0);
	if (game->e_count == 0)
		return (0);
	return (1);
}
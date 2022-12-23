#include "so_long.h"


int	is_line_all_wall(char *line)
{
	const char wall = '1';
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != wall)
			return (0);
		i++;
	}
	return (1);
}

int is_line_component_valid(char *line)
{
	const char	*set = "01CEP";
	const char	wall = '1';
	int			idx;

	idx = 0;
	if (line[idx] != wall)
		return (0);
	while (line[idx] && line[idx + 1] != 0)
	{
		if (!is_in_set(line[idx],set))
			return (0);
		idx++;
	}
	if (line[idx] != wall)
		return (0);
	return (1);
}

int	is_map_valid_width(char **map)
{
	int	i;
	int len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int is_map_component_valid(char **map)
{
	int	i;
	const int height = ft_get_height(map);

	i = 0;
	while (i < height)
	{
		if (i == 0 || i == height - 1)
		{
			if (!is_line_all_wall(map[i]))
				return (0);
		}
		else
		{
			if (!is_line_component_valid(map[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int is_component_count_valid(t_info *board)
{
	if (board->total_c_count == 0)
		return (0);
	if (board->total_e_count != 1)
		return (0);
	if (board->total_p_count != 1)
		return (0);
	return (1);
}
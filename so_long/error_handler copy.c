# include "so_long.h"
//get_next_line 옮겨오기
//마지막에 개행 관련해서 처리하기
# include "get_next_line.c"
# include "get_next_line_utils.c"
# include <stdio.h>
# include "ft_split.c"

char	**read_map(char *file_name)//이거는 에러 처리가 아님
{
	int	fd;
	char *line;
	char *map_str;
	char **answer;

	map_str = NULL;
	fd = open(file_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		map_str = ft_strjoin(map_str, line);
		free(line);
	}
	if (!map_str)
		return (NULL);
	answer = ft_split(map_str, '\n');
	free(map_str);
	close(fd);
	return (answer);
}

int ft_get_height(char **map)//utils애 가야하는 부분
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int is_map_valid_width(char **map)
{
	int	i;
	int len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			printf("%s", "Error\n");
			exit(0);
			return (0);
		}
		i++;
	}
	return (1);
}

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

int	is_in_set(char factor, const char *set)
{
	int	idx;

	idx = 0;
	while (set[idx])
	{
		if (set[idx] == factor)
			return (1);
		idx++;
	}
	return (0);
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

int is_map_component_valid(char **map)
{
	int	i;
	const int height = ft_get_height(map);

	i = 0;
	while (i < height)
	{
		if (i == 0 || i == height - 1)
			if (is_line_all_wall(map[i]))
				return (0);
		else
			if (is_line_component_valid(map[i]))
				return (0);
		i++;
	}
	return (1);
}

t_info	*init_info(char **map)
{
	t_info	*info;
	info = malloc(sizeof(t_info));

	info->total_c_count = 0;
	info->total_e_count = 0;
	info->total_p_count = 0;
	info->map = map;
	info->width = ft_strlen(map[0]);
	info->height = ft_get_height(map);
	return (info);
}

t_info	*get_map_component_count(char **map)
{
	t_info	*board;
	int		y;
	int		x;

	y = 0;
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

int is_component_count_valid(t_info *board)
{
	if (board->total_c_count == 0)
		return (0);
	if (board->total_e_count == 0)
		return (0);
	if (board->total_p_count != 1)
		return (0);
	return (1);
}

void check_map_valid(char **map)
{
	if (!is_map_valid_width(map) ||
		!is_map_component_valid(map))
		{
			//대충 종료시키는 함수
			exit(0);
		}
}

void check_component_count_valid(t_info *board)
{
	if (!is_component_count_valid(board))
	{
		//대충 종료시키는 함수
		exit(0);
	}
}

//에러 처리

#include <stdio.h>
int main ()
{
	char **map =read_map("example.txt");
	check_map_valid(map);
	t_info *board = get_map_component_count(map);
	check_component_count_valid(board);

	int i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	system("leaks a.out");
}
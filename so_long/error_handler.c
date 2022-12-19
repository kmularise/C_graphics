# include "so_long.h"
//get_next_line 옮겨오기
//마지막에 개행 관련해서 처리하기
# include "get_next_line.c"
# include "get_next_line_utils.c"
# include <stdio.h>
# include "ft_split.c"

int	ft_strlen_without_new_line(char *line)
{
	int len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		return (len - 1);
	return (len);
}

int	is_end_of_file(char *line)
{
	int len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		return (0);
	return (1);
}

int	is_factor_effective_start_or_end(char *line)
{
	const char	wall = '1';
	int			idx;

	idx = 0;
	while (line[idx] && line[idx] != '\n')
	{
		if (line[idx] != wall)
			return (0);
		idx++;
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

int	is_factor_effective_middle(char *line)
{
	const char	*set = "01CEP";
	const char	wall = '1';
	int			idx;

	idx = 0;
	if (line[idx] != wall)
		return (0);
	while (line[idx] && line[idx + 1] != '\n')
	{
		if (!is_in_set(line[idx],set))
			return (0);
		idx++;
	}
	if (line[idx] != wall)
		return (0);
	return (1);
}

int	is_line_valid(char *line, int idx)
{
	if (idx == 0 || is_end_of_file(line))
		return (is_factor_effective_start_or_end(line));
	return (is_factor_effective_middle(line));
}

void	set_game(t_game *game, char* line)//초반부분이나  시작 부분에서 유효한지 체크해주어야 함.
{
	game->height = 0;
	game->width = ft_strlen_without_new_line(line);
	game->map_str = NULL;
}

void	ft_free(t_game *game, char *line)
{
	if (line)
		free(line);
	if (game)
	{
		free(game->map_str);
		free(game);
	}
}

int	is_map_component_valid(char *map_str)
{
	int	c_count;
	int	e_count;
	int	p_count;
	int	idx;

	c_count = 0;
	e_count = 0;
	p_count = 0;
	idx = 0;
	while (map_str[idx])
	{
		if (map_str[idx] == 'C')
			c_count++;
		if (map_str[idx] == 'E')
			e_count++;
		if (map_str[idx] == 'P')
			p_count++;
		idx++;
	}
	if (c_count == 0 || e_count == 0 || p_count != 1)
		return (0);
	return (1);
}

int	read_map(char *file_name, t_game *game)
{
	int		fd;
	char	*line;
	int		line_len;
	int		idx;

	fd = open(file_name, O_RDONLY);
	idx = 0;
	while (1)//줄별로 확인할 것들
	{
		line = get_next_line(fd);
		if (!line)
		{
			ft_free(game, line);
			return (ERROR_TAG);
		}
		if (idx == 0)
			set_game(game, line);
		//하나로 합칠 수 있으면 합치기
		if (game->width != ft_strlen_without_new_line(line))
		{
			ft_free(game, line);
			return (ERROR_TAG);
		}
		if (!is_line_valid(line, idx))
		{
			ft_free(game, line);
			return (ERROR_TAG);
		}
		//에러 나는 것들 하나로 합칠 수 있는 거 합치기
		game->map_str = ft_strjoin(game->map_str, line);
		if (is_end_of_file(line))
		{
			free(line);
			break ;
		}
		free(line);
		idx++;
	}
	if (!is_map_component_valid(game->map_str))
	{
		ft_free(game, NULL);
		return (ERROR_TAG);
	}
	//printf("%s", game->map_str);
	close(fd);
	return (SUCCESS_TAG);
}

//파일을 읽는 부분

// int is_error()//data형은 구조체 : map
// {

// }

int main()
{
	t_game *game;
	char **map;
	int read_flag;

	game = malloc(sizeof(t_game));
	read_flag = read_map("example1.txt", game);
	if (read_flag == ERROR_TAG)
	{
		printf("Error\n");
		system("leaks a.out");
		return (0);
	}
	//printf("%d", read_flag);
	// printf("check:\n%s",game->map_str);
	// if (read_flag == ERROR_TAG)
	// 	return (0);
	// map = ft_split(game->map_str, '\n');
	// printf("\ncheck\n");
	// while (*map)
	// {
	// 	printf("%s\n", *map);
	// 	map++;
	// }

	system("leaks a.out");
	return (0);
}
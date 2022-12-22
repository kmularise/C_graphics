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
	game->height = 1;
	game->width = ft_strlen_without_new_line(line);
}

void	ft_free(char *ptr1, char *ptr2)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);

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
	char	*map_str;

	fd = open(file_name, O_RDONLY);
	idx = 0;
	while (1)//줄별로 확인할 것들
	{
		line = get_next_line(fd);
		if (!line)
		{
			ft_free(line, map_str);
			return (ERROR_TAG);
		}
		if (idx == 0)
			set_game(game, line);
		//하나로 합칠 수 있으면 합치기
		if (game->width != ft_strlen_without_new_line(line)
			|| !is_line_valid(line, idx))
		{
			ft_free(line, map_str);
			return (ERROR_TAG);
		}
		//에러 나는 것들 하나로 합칠 수 있는 거 합치기
		map_str = ft_strjoin(map_str, line);
		if (is_end_of_file(line))
		{
			free(line);
			break ;
		}
		free(line);
		idx++;
		(game->height)++;
	}
	if (!is_map_component_valid(map_str))
	{
		ft_free(map_str, NULL);
		return (ERROR_TAG);
	}
	printf("%s", map_str);
	game->map = ft_split(map_str, '\n');
	//printf("%s", game->map_str);
	close(fd);
	return (SUCCESS_TAG);
}

//파일을 읽는 부분

// int is_error()//data형은 구조체 : map
// {

// }

//#include "put_image2.c"
#include "error_handler2.c"

int main()
{
	t_game *game;
	char **map;
	int read_flag;

	game = malloc(sizeof(t_game));
	read_flag = read_map("example3.txt", game);
	if (read_flag == ERROR_TAG)
	{
		printf("Error\n");
		system("leaks a.out");
		return (0);
	}
	//printf("\n check: %d\n", game->height);
	// int i = 0;
	// while ((game->map)[i])
	// {
	// 	printf("%s\n", (game->map)[i]);
	// 	i++;
	// }
	printf("%d",is_map_connected(game));
	// init_window(game);
	// put_background_image(game);
	// put_background_image2(game);

	// //put_component_image(game);
	// mlx_loop(game->mlx);
	// system("leaks a.out");

	return (0);
}
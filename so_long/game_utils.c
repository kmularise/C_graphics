/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:14:52 by yuikim            #+#    #+#             */
/*   Updated: 2022/12/24 15:26:59 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	**read_map(char *file_name)
{
	int		fd;
	char	*line;
	char	*map_str;
	char	**answer;

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

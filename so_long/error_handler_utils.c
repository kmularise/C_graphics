/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:06:28 by yuikim            #+#    #+#             */
/*   Updated: 2022/12/24 15:06:46 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
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

void	ft_free_d_ptr(char **double_ptr)
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

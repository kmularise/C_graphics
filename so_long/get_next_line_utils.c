/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:13:00 by yuikim            #+#    #+#             */
/*   Updated: 2022/12/23 08:27:38 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (src[count])
	{
		count++;
	}
	if (size)
	{
		while (src[i] && (i + 1 < size))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (count);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s) + 1)
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*answer;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	answer = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!answer)
		return (NULL);
	ft_strlcpy(answer, s1, s1_len + 1);
	ft_strlcpy(answer + s1_len, s2, s2_len + 1);
	free(s1);
	return (answer);
}

t_fd_list	*new_fd_node(int fd)
{
	t_fd_list	*new_node;

	new_node = (t_fd_list *)malloc(sizeof(t_fd_list));
	if (!new_node)
		return (NULL);
	new_node->backup = NULL;
	new_node->fd = fd;
	new_node->next = NULL;
	return (new_node);
}

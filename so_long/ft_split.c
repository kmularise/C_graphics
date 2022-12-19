/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:29:44 by yuikim            #+#    #+#             */
/*   Updated: 2022/12/19 15:03:46 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	ft_word_count(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
			count++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static size_t	ft_word_len(char *s, size_t s_idx, char c)
{
	size_t	i;

	i = 0;
	while (s[i + s_idx] && s[i + s_idx] != c)
		i++;
	return (i);
}

static void	ft_assign(size_t s_idx, char *answer_factor, char *s, char c)
{
	size_t	i;

	i = 0;
	while (i < ft_word_len(s, s_idx, c))
	{
		answer_factor[i] = s[s_idx + i];
		i++;
	}
	answer_factor[i] = 0;
}

static void	ft_free2(char **answer, int last_idx)
{
	int	i;

	i = 0;
	while (i < last_idx)
	{
		free(answer[last_idx - 1 - i]);
		i++;
	}
	free(answer);
}

char	**ft_split(char *s, char c)
{
	char	**answer;
	int		i;
	size_t	s_idx;

	answer = (char **)malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!answer)
		return (NULL);
	i = -1;
	s_idx = 0;
	while (++i < (int)ft_word_count(s, c))
	{
		while (s[s_idx] && s[s_idx] == c)
			s_idx++;
		answer[i] = (char *)malloc(sizeof(char)
				* (ft_word_len(s, s_idx, c) + 1));
		if (!answer[i])
		{
			ft_free2(answer, i);
			return (NULL);
		}
		ft_assign(s_idx, answer[i], s, c);
		s_idx += ft_word_len(s, s_idx, c);
	}
	answer[i] = 0;
	return (answer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:53:17 by yuikim            #+#    #+#             */
/*   Updated: 2022/12/12 19:05:16 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_fd_list
{
	int					fd;
	char				*backup;
	struct s_fd_list	*next;
}	t_fd_list;

char		*get_next_line(int fd);
void		remove_node(t_fd_list *curr_node, t_fd_list **head);
t_fd_list	*find_node(t_fd_list **head, int fd);
t_fd_list	*read_fd_node(t_fd_list *current_fd_node, t_fd_list **head, int fd);
char		*extract_line(t_fd_list *node);
t_fd_list	*new_fd_node(int fd);
size_t		ft_strlen(char *s);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);

#endif
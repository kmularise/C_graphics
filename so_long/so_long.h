/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:27:28 by yuikim            #+#    #+#             */
/*   Updated: 2022/12/24 16:19:32 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "get_next_line.h"
# include "error_handler.h"
# include "ft_printf.h"

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*img;
	int		c_count;
	int		total_c_count;
	int		move;
	int		p_y;
	int		p_x;
}	t_game;

char	**ft_split(char *s, char c);

t_game	*set_game(t_info *player);
int		put_player_image(t_game *game, char *path);
int		put_background_image(t_game *game);
int		put_component_image(t_game *game);
char	*get_xpm_path(char component);

int		program_exit(t_game *game);

int		exit_hook(void);
int		program_exit(t_game *game);
int		event_handle(t_game *game);
int		key_press(int keycode, t_game *game);

void	move(int next_x, int next_y, t_game *game);
void	get_collective(t_game *game);
void	check_game_end(t_game *game);
int		check_valid_move(int next_y, int next_x, t_game *game, int keycode);
char	*get_image_path(int keycode);
void	show_error(char *error_message);
char	**read_map(char *file_name);
void	start(t_game *game);

# define KEY_PRESS 2
# define BUTTON_PRESS 4
# define KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define UNIT_PIXEL 64

# define PLAYER_FRONT "./images/character_front.xpm"
# define PLAYER_BACK "./images/character_back.xpm"
# define PLAYER_RIGHT "./images/character_right.xpm"
# define PLAYER_LEFT "./images/character_left.xpm"

#endif

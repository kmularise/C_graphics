#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"

// typedef struct s_board
// {
// 	int		width;
// 	int		height;
// 	char	**map;
// } t_board;

typedef struct s_info
{
	int	y;
	int	x;
	int	total_c_count;
	int	total_e_count;
	int	total_p_count;
	int	width;
	int height;
	char	**map; 
}	t_info;

typedef struct s_game
{
	int		height;
	int		width;
	char	**map;
	void	*mlx;
	void	*win;
	void	*img;
	int		c_count;
	int		e_count;
}	t_game;

typedef struct s_position
{
	int	y;
	int	x;
	int c_count;
}	t_position;

char	**ft_split(char *s, char c);

# define KEY_PRESS 2
# define BUTTON_PRESS 4
# define KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define ERROR_TAG -1
# define SUCCESS_TAG 0
# define ERROR_MESSAGE "Error\n"
# define UNIT_PIXEL 64

#endif
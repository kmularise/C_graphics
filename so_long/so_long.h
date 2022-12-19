#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "mlx.h"
# include "get_next_line.h"

typedef struct s_game
{
	int		height;
	int		width;
	char	*map_str;
}	t_game;

typedef struct s_position
{
	int	y;
	int	x;
}	t_position;

char	**ft_split(char *s, char c);

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define ERROR_TAG -1
# define SUCCESS_TAG 0
# define ERROR_MESSAGE "Error\n"

#endif
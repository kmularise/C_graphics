#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

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

int ft_get_height(char **map);
int	is_in_set(char factor, const char *set);
t_info	*init_info(char **map);
char	**make_2dim_zero(int height, int width);
void ft_free_d_ptr(char **double_ptr);

int	is_line_all_wall(char *line);
int is_line_component_valid(char *line);
int	is_map_valid_width(char **map);
int is_map_component_valid(char **map);
int is_component_count_valid(t_info *board);

t_info	*set_player(t_info *board);
int	dfs(int x, int y, t_info *player, char **visited);
int	is_map_connected(t_info *player, t_info *board);

t_info	*get_map_component_count(char **map);
void check_component_count_valid(t_info *board);
void check_map_valid(char **map);
void check_map_connected(t_info *player, t_info *board);

#endif
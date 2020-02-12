#   ifndef HEADER_H
#   define HEADER_H
#   include <stdlib.h>
#   include <unistd.h>
#   include <fcntl.h>
#   define MAX_NUM 5000000

int		new_line_check(char idx);
int		ft_line_check(char *map);
int		ft_obstacle_check(char *map);
int		ft_printable_check(void);
int		ft_character_check(void);
char	**ft_convert_map_arr(char *map);
int		ft_strlen(char *str);
int		is_valid_map(char *map);
void	ft_print(char **map);
void	ft_2d_int_free(int **obj);
void	ft_2d_char_free(char **obj);
void	ft_init_dp_map(int **dp_map);
void	ft_fill_value(int **dp_map, int row, int col);
void	ft_fill_dp_map(int **dp_map, char **map, int *max_value, int *max_coord);
void	ft_convert_map(char **map, int max_value, int *max_coord);
void	ft_solver(char **map);
#   endif

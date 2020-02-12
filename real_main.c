/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:25:58 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/12 10:53:28 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
int     g_line;
int     g_column;
char    g_empty_ch;
char    g_obstacle_ch;
char    g_full_ch;
char	*g_first_map_ch;

void	ft_init_dp_map(int dp_map[g_line + 1][g_column + 1]);
void	ft_fill_value(int dp_map[g_line + 1][g_column + 1], int row, int col);
void	ft_fill_dp_map(int dp_map[g_line + 1][g_column + 1], char *map[], 
                        int *max_value, int *max_coord);

int		main (int argc, char **argv)
{
	char	map[MAX_NUM];
	int		fd;
	int		idx;

	idx = 1;
	while (1)
	{
		if (argc == 1)
			read(0, map, MAX_NUM);
		else
			fd = open(argv[idx++], O_RDONLY);
			read(fd, map, MAX_NUM);
		if (is_valid_map(map))
			write(2, "error\n", 6);

		char **temp;
		temp = ft_convert_map_arr(g_first_map_ch);
		//for (int i = 0 ; i < g_line ; i++)
		//	printf("%s\n", temp[i++]);
		ft_solver(temp);
		// free 함수
		if (idx == argc)
			break;
	}
	return (0);
}

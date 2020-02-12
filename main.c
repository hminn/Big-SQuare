/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:25:58 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/12 17:15:55 by hyeokim          ###   ########.fr       */
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

int		main (int argc, char **argv)
{
	char	map[MAX_NUM];
	int		fd;
	int		idx;
	char	**temp;

	idx = 1;
	while (1)
	{
		if (argc == 1)
			read(0, map, MAX_NUM);
		else
		{
			fd = open(argv[idx++], O_RDONLY);
			read(fd, map, MAX_NUM);
		}
		if (is_valid_map(map))
			write(2, "error\n", 6);
		temp = ft_convert_map_arr(g_first_map_ch);
		ft_solver(temp);
		ft_2d_char_free(temp);
		close(fd);
		if (idx == argc)
			break;
	}
	return (0);
}

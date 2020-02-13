/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:25:58 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/13 14:55:26 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		g_line;
int		g_column;
char	g_empty_ch;
char	g_obstacle_ch;
char	g_full_ch;
char	*g_first_map_ch;

int		main(int argc, char **argv)
{
	char	*map;
	int		map_len;
	int		idx;
	char	**temp;

	idx = 1;
	if (argc == 1)
		std_print();
	else
		while (idx < argc)
		{
			map_len = ft_argv_len(argv[idx]);
			map = (char *)malloc(sizeof(char) * (map_len + 1));
			ft_argv_input(map, argv[idx++]);
			if (is_valid_map(map))
			{
				write(2, "map error\n\n", 11);
				continue ;
			}
			temp = ft_convert_map_arr(g_first_map_ch);
			ft_solver(temp, idx, argc);
			ft_2d_char_free(temp);
			free(map);
		}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:25:58 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/12 21:38:49 by hyeokim          ###   ########.fr       */
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

void	std_input(int fd)
{
	char	*line_text;
	int		loop;

	line_text = (char *)malloc(sizeof(char) * 100);
	read(0, line_text, 100);
	if ((loop = is_valid_first(line_text)))
	{
		write(fd, line_text, ft_strlen(line_text));
		write(fd, "\n", 1);
		free(line_text);
		while (loop--)
		{
			line_text = (char *)malloc(sizeof(char) * 100);
			read(0, line_text, 100);
			write(fd, line_text, ft_strlen(line_text));
			write(fd, "\n", 1);
			if (loop == 0)
				write(fd, "\0", 1);
			free(line_text);
		}
	}
}

int		main (int argc, char **argv)
{
	char	map[MAX_NUM];
	int		fd;
	int		idx;
	char	**temp;

	idx = 1;
	while (idx < argc)
	{
		if (argc == 1)
		{
			fd = open("temp.txt", O_CREAT | O_RDWR, S_IWRITE | S_IREAD);
			std_input(fd);
			close(fd);
		}
		else
			fd = open(argv[idx++], O_RDONLY);
		//fd = open("temp.txt", O_RDONLY);
		read(fd, map, MAX_NUM);
		if (is_valid_map(map))
		{
			write(2, "map error\n\n", 11);
			continue;
		}
		temp = ft_convert_map_arr(g_first_map_ch);
		ft_solver(temp);
		ft_2d_char_free(temp);
		close(fd);
	}
	return (0);
}

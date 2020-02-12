/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 22:23:10 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/13 03:18:47 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern char *g_first_map_ch;

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

void	std_print(void)
{
	int		fd;
	char	map[MAX_NUM];
	char	**temp;

	fd = open("temp.txt", O_RDWR, S_IWRITE | S_IREAD);
	std_input(fd);
	close(fd);
	fd = open("temp.txt", O_RDONLY);
	read(fd, map, MAX_NUM);
	if (is_valid_map(map))
	{
		write(2, "map error\n\n", 11);
		return ;
	}
	temp = ft_convert_map_arr(g_first_map_ch);
	ft_solver(temp, 0, 0);
	ft_2d_char_free(temp);
	open("temp.txt", O_TRUNC);
	close(fd);
}

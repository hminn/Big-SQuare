/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 00:44:48 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/13 02:01:14 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_map_len(char *str)
{
	int		cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

void	ft_input_map(char *map, char *buf)
{
	int		idx;

	idx = 0;
	while (buf[idx])
	{
		map[idx] = buf[idx];
		idx++;
	}
	map[idx] = 0;
}

int		ft_argv_len(char *argv)
{
	char	buf[MAX_NUM];
	int		result;
	int		fd;
	int		idx;

	idx = 0;
	while (idx < MAX_NUM)
		buf[idx++] = 0;
	fd = open(argv, O_RDONLY);
	read(fd, buf, MAX_NUM);
	result = ft_map_len(buf);
	close(fd);
	return (result);
}

void	ft_argv_input(char *map, char *argv)
{
	char	buf[MAX_NUM];
	int		fd;

	fd = open(argv, O_RDONLY);
	read(fd, buf, MAX_NUM);
	ft_input_map(map, buf);
	close(fd);
}

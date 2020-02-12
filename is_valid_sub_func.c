/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_sub_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:09:35 by sjeon             #+#    #+#             */
/*   Updated: 2020/02/13 02:04:55 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int		g_line;
extern int		g_column;
extern char		g_empty_ch;
extern char		g_obstacle_ch;
extern char		g_full_ch;
extern char		*g_first_map_ch;

int		new_line_check(char idx)
{
	if (idx != '\n')
		return (1);
	return (0);
}

int		ft_line_check(char *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	g_column = ft_strlen(&map[i + 1]);
	if (new_line_check(map[i]))
	{
		return (1);
	}
	while (j++ < g_line)
	{
		if (new_line_check(map[i + j * (g_column + 1)]))
			return (1);
	}
	if (map[i + (j - 1) * (g_column + 1) + 1])
		return (1);
	return (0);
}

int		ft_obstacle_check(char *map)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (map[i])
	{
		if (!(map[i] == g_empty_ch || map[i] == g_obstacle_ch
			|| map[i] == g_full_ch || map[i] == '\n'))
			return (1);
		if (map[i] == g_obstacle_ch)
			count++;
		i++;
	}
	if (count == g_line * g_column)
		return (1);
	return (0);
}

int		ft_printable_check(void)
{
	if (!(g_empty_ch > 31 && g_empty_ch < 127))
		return (1);
	if (!(g_obstacle_ch > 31 && g_obstacle_ch < 127))
		return (1);
	if (!(g_full_ch > 31 && g_full_ch < 127))
		return (1);
	return (0);
}

int		ft_character_check(void)
{
	if (g_empty_ch == g_obstacle_ch || g_empty_ch == g_full_ch
		|| g_obstacle_ch == g_full_ch)
		return (1);
	return (0);
}

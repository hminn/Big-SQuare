/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:45:10 by sjeon             #+#    #+#             */
/*   Updated: 2020/02/13 02:03:25 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern	int		g_line;
extern	int		g_column;
extern	char	g_empty_ch;
extern	char	g_obstacle_ch;
extern	char	g_full_ch;
extern	char	*g_first_map_ch;

char	**ft_convert_map_arr(char *map)
{
	int		i;
	int		j;
	int		k;
	char	**map_arr;

	i = 0;
	map_arr = (char **)malloc(sizeof(char *) * g_line);
	while (i < g_line)
		map_arr[i++] = (char *)malloc(sizeof(char) * g_column);
	i = 0;
	j = 0;
	k = 0;
	while (i < g_line)
	{
		j = 0;
		while (j < g_column)
		{
			map_arr[i][j] = map[k++];
			j++;
		}
		k++;
		i++;
	}
	return (map_arr);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		is_valid_first(char *map)
{
	int	temp;
	int	i;

	i = 0;
	temp = 0;
	while (map[i] >= '0' && map[i] <= '9')
		temp = temp * 10 + (map[i++] - 48);
	if (!(g_line = temp))
		return (0);
	return (temp);
}

int		is_valid_map(char *map)
{
	int	temp;
	int	i;

	i = 0;
	temp = 0;
	while (map[i] >= '0' && map[i] <= '9')
		temp = temp * 10 + (map[i++] - 48);
	if (!(g_line = temp))
		return (1);
	g_empty_ch = map[i++];
	g_obstacle_ch = map[i++];
	g_full_ch = map[i++];
	g_first_map_ch = &map[i + 1];
	if (ft_printable_check() || ft_character_check() ||
		ft_line_check(&map[i]) || ft_obstacle_check(&map[i]))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:45:10 by sjeon             #+#    #+#             */
/*   Updated: 2020/02/12 18:08:22 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern	int		g_line;
extern	int		g_column;
extern	char	g_empty_ch;
extern	char	g_obstacle_ch;
extern	char	g_full_ch;
extern char     *g_first_map_ch;

/*
** 일차원배열 map을 2차원 동적배열로 변환하는 함수 / 추후에 free 필요
*/

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

/*
** 주어진 맵이 유효한 맵인지 확인하는 함수
** 첫 행에서 숫자로 시작하지 않는 경우 오류처리
*/

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

// int		main(int argc, char *argv[])
// {
// 	char map[] = "3oxf\nooox\nxoxx\nxxxx\n";
// 	int a;
// 	char **map_arr;
// 	a = is_vaild_map(map);
// 	if (a == 0)
// 		printf("<<result : GOOD>>\n");
// 	else
// 		printf("<<result : NOOO>>\n");
// 	map_arr = ft_convert_map_arr(g_first_map_ch);
	
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;
// 	while (i < g_line)
// 	{
// 		j = 0;
// 		while (j < g_column)
// 		{
// 			printf("%c \t", map_arr[i][j]);
// 			j++;
// 			k++;
// 		}
// 			printf("\n");
// 		i++;
// 	}
// 	return (0);
// }

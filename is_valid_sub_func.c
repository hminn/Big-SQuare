/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_sub_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 01:09:35 by sjeon             #+#    #+#             */
/*   Updated: 2020/02/12 02:26:07 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int      g_line;
extern int      g_column;
extern char     g_empty_ch;
extern char     g_obstacle_ch;
extern char     g_full_ch;
extern char     *g_first_map_ch;

/*
** 현재 문자의 위치에 개행이 있는지 확인하는 함수
*/

int		new_line_check(char idx)
{
	if (idx != '\n')
		return (1);
	return (0);
}

/*
** 처음에 개행으로 시작하는지 확인을 하여, 첫행에 숫자 이후 문자 3개가 차례로 왔는지 체크
** 마지막행의 끝에도 개행문자가 있어야함 / 없으면 오류로 처리
** 마지막행의 개행문자 이후에 널이 있는 것으로 간주, 이외에 다른 문자가 오면 오류로 처리
*/

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

/*
** 첫행에 언급된 문자로만 이루어졌는지, 모든부분이 obstacle인지 체크
*/

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

/*
** 주어진 문자가 출력가능한 문자인지 확인
*/

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

/*
** 첫 행에 언급된 문자 중 중복이 존재하면 오류
*/

int		ft_character_check(void)
{
	if (g_empty_ch == g_obstacle_ch || g_empty_ch == g_full_ch
		|| g_obstacle_ch == g_full_ch)
		return (1);
	return (0);
}

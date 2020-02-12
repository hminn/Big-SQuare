/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:21:23 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/12 10:53:25 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
extern int	g_line;
extern int	g_column;
extern char	g_empty_ch;
extern char	g_obstacle_ch;
extern char g_full_ch;

void	ft_init_dp_map(int dp_map[g_line + 1][g_column + 1])
{
	int		i;

	i = 0;
	while (i <= g_line)
		dp_map[i++][0] = 0;
	i = 0;
	while (i <= g_column)
		dp_map[0][i++] = 0;
}

void	ft_fill_value(int dp_map[g_line + 1][g_column + 1], int row, int col)
{
	int		min;

	min = dp_map[row - 1][col - 1];
	if (min > dp_map[row - 1][col])
		min = dp_map[row - 1][col];
	if (min > dp_map[row][col - 1])
		min = dp_map[row][col - 1];
	dp_map[row][col] = min + 1;
}

void	ft_fill_dp_map(int dp_map[g_line + 1][g_column + 1], char *map[g_line],
						int *max_value, int *max_coord)
{
	int		row;
	int		col;

	row = 0;
	while (row < g_line)
	{
		col = 0;
		while (col < g_column)
		{
			if (map[row][col] == g_obstacle_ch)
				dp_map[row + 1][col + 1] = 0;
			else
				ft_fill_value(dp_map, row + 1, col + 1);
			if (*max_value < dp_map[row + 1][col + 1])
			{
				*max_value = dp_map[row + 1][col + 1];
				max_coord[0] = row;
				max_coord[1] = col;
			}
			col++;
		}
		row++;
	}
}

void	ft_convert_map(char *map[g_line], int max_value, int *max_coord)
{
	int	row;
	int	col;
	int	init_col;

	row = max_coord[0] - (max_value - 1);
	init_col = max_coord[1] - (max_value - 1);
	while (row <= max_coord[0])
	{
		col = init_col;
		while (col <= max_coord[1])
			map[row][col++] = g_full_ch;
		row++;
	}
}

void	ft_solver(char *map[g_line])
{
	int		max_value;
	int		max_coord[2];
	int		dp_map[g_line + 1][g_column + 1];
	int		i;

	i = 0;
	max_value = 0;
	ft_init_dp_map(dp_map);
	ft_fill_dp_map(dp_map, map, &max_value, max_coord);
	ft_convert_map(map, max_value, max_coord);
	printf("%d / %d / %d \n", max_value, max_coord[0], max_coord[1]);
	i = 0;
	while (i < g_line)
		printf("%s \n", map[i++]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:24:19 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/13 03:21:16 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int	g_line;
extern int	g_column;

void	ft_print(char **map, int check, int argc)
{
	int			idx;

	idx = 0;
	while (idx < g_line)
	{
		write(1, map[idx++], g_column);
		write(1, "\n", 1);
	}
	if (check < argc)
		write(1, "\n", 1);
}

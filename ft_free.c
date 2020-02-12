/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:55:00 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/12 21:06:08 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern int	g_line;

void	ft_2d_int_free(int **obj)
{
	int		idx;

	idx = 0;
	while (idx < g_line + 1)
		free(obj[idx++]);
	free(obj);
}

void	ft_2d_char_free(char **obj)
{
	int		idx;

	idx = 0;
	while (idx < g_line)
		free(obj[idx++]);
	free(obj);
}

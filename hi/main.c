/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:25:58 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/12 01:30:59 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_solve.c"
#include <stdio.h>

#define MAX_NUM 10000

int     g_row = 17;
int		g_column = 60;
char    g_empty_ch = '.';
char    g_obstacle_ch = 'o';
char    g_full_ch = 'x';

int		main (void)
{
	char	*map[17] = {"...............oooooooooooo........ooooooooooooooooooo......",
".............oooooooooooooo......oooooooooooooooooooooo.....",
"............ooooooooooooo.......ooooooooooooooooooooooo.....",
"..........ooooooooooooo........ooo.oooooooooooooooooooo.....",
".........oooooooooooo..........o..oo.oooooo....oooooooo.....",
".......ooooooooooooo............oooooooooo....ooooooooo.....",
".....ooooooooooooo..........................ooooooooooo.....",
"...ooooooooooooo.........................oooooooooooooo.....",
"..oooooooooooo.........................oooooooooooooooo.....",
".ooooooooooooooooooooooo.o...........ooo.ooooooooooooo......",
".ooooooooooooooooooooo.oo.o........oo.ooooooooooooo.........",
".ooooooooooooooooooooooooo.......ooooooooooooo..............",
".oooooooooooooooooooooooooo.....oooooooooooooo....ooooo.....",
"..ooooooooooooooooooooooooo....oooooooooooooo....oooooo.....",
".................oooooooooo...ooooooooooooooooooooooooo.....",
".................oooooooooo...ooooooooooooooooooooooooo.....",
"..................ooooooooo.....ooooooooooooooooooooooo....."};
	int i = 0;

	while (i < g_row)
		printf("%s\n", map[i++]); 
	ft_solver(map);
	return (0);
}

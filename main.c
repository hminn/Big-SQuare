/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:25:58 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/11 19:03:41 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_NUM 10000

int		main (int argc, char **argv)
{
	char	map[MAX_NUM];
	int		fd;
	int		idx;

	idx = 1;
	if (argc == 1)
	{
		read(0, map, MAX_NUM);
		ft_error(map);
		return (0);
	}
	while (idx < argc)
	{
		fd = open(argv[idx], O_RDONLY);
		read(fd, map, MAX_NUM);
		if (ft_error_check(map))
		{
			write(error);
			continue;
		}
		ft_solver();
		idx++;
	}
	return (0);
}

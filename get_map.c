/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:14:30 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/15 17:31:05 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**get_map(char *str)
{
	int		fd;
	int		i;
	int		j;
	int		**map;
	char	**unmodify_map;
	char	*line;

	i = 0;
	if (!(fd = open(str, O_RDONLY)))
		ft_error("Error: Open failed.\n", EXIT_FAILURE);
	while (get_next_line(fd, &line) >= 1)
	{
		j = 0;
		unmodify_map = ft_strsplit(line, ' ');
		if (!(map[i] = (int *)malloc(sizeof(int) * env.xmax)))
			ft_error("Error: Malloc failed.\n", EXIT_FAILURE);
		while (unmodify_map[j])
		{
			map[i][j] = ft_atoi(unmodify_map[j]);
			j++;
		}
		i++;
		ft_strdel(&line);
	}
	return (0);
}

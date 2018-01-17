/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:14:30 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/17 15:42:45 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		check_size(t_map *map, char **unmodify_map)
{
	int		width;

	width = 0;
	while (unmodify_map[width])
		width++;
	map->xmax = width;
}

static void		check_height(t_map *map, char *argv)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	fd = 0;
	line = NULL;
	if (!(fd = open(argv, O_RDONLY)))
		ft_error("Error: open failed.\n", EXIT_FAILURE);
	while (get_next_line(fd, &line) >= 1)
		height++;
	map->ymax = height;
	ft_strdel(&line);
	close(fd);
}

void		get_map(t_env *env, t_map *mp, char *str, int fd)
{
	int		i;
	int		j;
	char	**unmodify_map;
	char	*line;

	i = 0;
	check_height(mp, str);
	if (!(mp->map = (int **)malloc(sizeof(int *) * mp->ymax)))
		ft_error("Error: Malloc failed.\n", EXIT_FAILURE);
	while (get_next_line(fd, &line) >= 1)
	{
		j = 0;
		unmodify_map = ft_strsplit(line, ' ');
		check_size(mp, unmodify_map);
		if (!(mp->map[i] = (int *)malloc(sizeof(int) * mp->xmax + 1)))
			ft_error("Error: Malloc failed.\n", EXIT_FAILURE);
		while (unmodify_map[j])
		{
			mp->map[i][j] = ft_atoi(unmodify_map[j]);
			j++;
		}
		i++;
		ft_strdel(&line);
	}

	ft_strdel(&line);
	close(fd);
}

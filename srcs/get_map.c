/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:44:28 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/22 17:27:03 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		check_width(t_env *env, char **u_map)
{
	int		width;

	width = 0;
	while (u_map[width])
		width++;
	env->width = width;
}

static void		check_height(t_env *env, char *av)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	line = NULL;
	if (!(fd = open(av, O_RDONLY)))
		ft_error("Error: Open failed.\n", EXIT_FAILURE);
	while (get_next_line(fd, &line) >= 1)
		height++;
	env->height = height;
	ft_strdel(&line);
	close(fd);
}

void	get_map(t_env *env, char *av)
{
	char	**u_map;
	char	*line;
	int		fd;
	int		i;
	int		j;

	i = 0;
	line = NULL;
	if (!(fd = open(av, O_RDONLY)))
		ft_error("Error: Open failed.\n", EXIT_FAILURE);
	check_height(env, av);
	env->map = (int **)ft_xmalloc(sizeof(int *) * env->height);
	while (get_next_line(fd, &line) >= 1)
	{
		j = -1;
		u_map = ft_strsplit(line, ' ');
		check_width(env, u_map);
		env->map[i] = (int *)ft_xmalloc(sizeof(int) * env->width + 1);
		while (u_map[++j])
			env->map[i][j] = ft_atoi(u_map[j]);
		i++;
		ft_strdel(&line);
	}
	close(fd);
}

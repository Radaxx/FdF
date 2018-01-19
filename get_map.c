/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:14:30 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/19 11:32:39 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		check_width(t_env *env, char **unmodify_map)
{
	int			width;

	width = 0;
	while (unmodify_map[width])
		width++;
	env->width = width;
}

static void		check_height(t_env *env, char *argv)
{
	int			height;
	int			fd;
	char		*line;

	height = 0;
	fd = 0;
	line = NULL;
	if (!(fd = open(argv, O_RDONLY)))
		ft_error("Error: open failed.\n", EXIT_FAILURE);
	while (get_next_line(fd, &line) >= 1)
		height++;
	env->height = height;
	ft_strdel(&line);
	close(fd);
}

static t_dot	**copy_struct(t_dot **dot)
{
	t_dot		**tmp;
	int			i;

	i = 0;
	while (dot[i])
	{
		tmp[i] = dot[i];
		i++;
	}
	free(dot);
	return (tmp);
}

static t_dot	**ft_map(t_dot **map, char **unmodify_map, t_env *env)
{
	t_dot		**grid;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (map[i])
		i++;
	grid = (t_dot **)ft_xmalloc(sizeof(t_dot *) * (i + 1));
	grid = copy_struct(map);
	check_width(env, unmodify_map);
	grid[i] = (t_dot *)ft_xmalloc(sizeof(t_dot));
	env->depth_min = ft_atoi(unmodify_map[0]);
	env->depth_max = ft_atoi(unmodify_map[0]);
	while (unmodify_map[j])
	{
		grid[i][j].z = ft_atoi(unmodify_map[j]);
		j++;
	}
	grid[i] = NULL;
	return (grid);
}

void			get_map(t_env *env, char *av)
{
	int			i;
	int			j;
	int			fd;
	char		*line;
	char		**unmodify_map;

	i = 0;
	j = 0;
	env->width = 0;
	env->height = 0;
	if (!(fd = open(av, O_RDONLY)))
		ft_error("Error: Open failed.\n", EXIT_FAILURE);
	check_height(env, av);
	env->dot = (t_dot **)ft_xmalloc(sizeof(t_dot *));
	env->dot[0] = NULL;
	while (get_next_line(fd, &line) >= 1)
	{
		unmodify_map = ft_strsplit(line, ' ');
		env->dot = ft_map(env->dot, unmodify_map, env);
	}
	free(line);
	close(fd);
}

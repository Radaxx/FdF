/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:44:28 by aparabos          #+#    #+#             */
/*   Updated: 2018/02/02 14:17:35 by aparabos         ###   ########.fr       */
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
	if ((fd = open(av, O_RDONLY)) == -1)
		ft_error("Error: Open failed.");
	while (get_next_line(fd, &line) >= 1)
	{
		height++;
		ft_strdel(&line);
	}
	env->height = height;
	ft_strdel(&line);
	close(fd);
}

static void		array_to_int(t_env *env, t_var *var)
{
	while (env->u_map[var->j])
	{
		env->map[var->i][var->j] = ft_atoi(env->u_map[var->j]);
		ft_strdel(&(env->u_map[var->j]));
		var->j++;
	}
}

void			get_map(t_env *env, char *av)
{
	t_var		var;

	var.i = 0;
	if ((var.fd = open(av, O_RDONLY)) == -1)
		ft_error("Error: Open failed.");
	check_height(env, av);
	env->map = (int **)ft_xmalloc(sizeof(int *) * env->height + 1);
	while (get_next_line(var.fd, &var.line) >= 1)
	{
		var.j = 0;
		env->u_map = ft_strsplit(var.line, ' ');
		check_width(env, env->u_map);
		env->map[var.i] = (int *)ft_xmalloc(sizeof(int) * env->width);
		array_to_int(env, &var);
		var.i++;
		free(env->u_map);
		ft_strdel(&var.line);
	}
	env->map[var.i] = NULL;
	ft_strdel(&var.line);
	close(var.fd);
}

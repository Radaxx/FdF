/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:14:30 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/16 15:11:54 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	*get_map(t_env *env, char *str)
{
	int		fd;
	int		i;
	int		j;
	char	**unmodify_map;
	char	*line;

	i = 0;
	if (!(fd = open(str, O_RDONLY)))
		ft_error("Error: Open failed.\n", EXIT_FAILURE);
	check_height(env, str);
	if (!(env->map = (int **)malloc(sizeof(int *) * env->ymax)))
		ft_error("Error: Malloc failed.\n", EXIT_FAILURE);
	while (get_next_line(fd, &line) >= 1)
	{
		j = 0;
		unmodify_map = ft_strsplit(line, ' ');
		check_size(env, unmodify_map);
		if (!(env->map[i] = (int *)malloc(sizeof(int) * env->xmax + 1)))
			ft_error("Error: Malloc failed.\n", EXIT_FAILURE);
		while (unmodify_map[j])
		{
			env->map[i][j] = ft_atoi(unmodify_map[j]);
			j++;
		}
		i++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (env);
}

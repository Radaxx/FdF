/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 11:33:03 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/16 14:48:05 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check_height(t_env *env, char *str)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	line = NULL;
	if (!(fd = open(str, O_RDONLY)))
		ft_error("Error: Open failed.\n", EXIT_FAILURE);
	while (get_next_line(fd, &line) >= 1)
		height++;
	ft_strdel(&line);
	close(fd);
	env->ymax = height;
}

void		check_size(t_env *env, char **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	env->xmax = i;
}

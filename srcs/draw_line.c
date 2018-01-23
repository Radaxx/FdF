/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:13:29 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/23 15:31:05 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_line(t_dot *m1, t_dot *m2, t_env *env)
{
	t_dot		*dot;

	dot = (dot *)ft_xmalloc(sizeof(t_dot));

}

void		draw(t_env *env)
{
	int		i;

	i = -1;
	while (env->dot[++i])
	{
		if ((i + 1) % env->width != 0)
			draw_line(env->dot[i], env->dot[i + 1], env);
		if (i < ((env->width * env->height) - env->height))
			draw_line(env->dot[i], env->dot[i + env->width], env);
	}
}

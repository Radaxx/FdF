/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:14:31 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/23 15:00:25 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_var(t_env *env)
{
	int		i;

	i = -1;
	while (env->dot[++i])
	{
		env->dot[i]->x_max = env->dot[i]->x + (env->dot[i]->x * env->zoom);
		env->dot[i]->y_max = env->dot[i]->y + (env->dot[i]->y * env->zoom);
		env->dot[i]->z_max = env->dot[i]->z + (env->dot[i]->z * env->depth);
		env->dot[i]->x_min = (env->dec_width * env->dot[i]->x_max) -
			(env->dec_height * env->dot[i]->y_max);
		env->dot[i]->y_min = (env->dot[i]->z_max + ((env->dec_width / 2) *
			env->dot[i]->x_max) + ((env->dec_height / 2) * env->dot[i]->y_max));
		env->dot[i]->x_min = ((env->dot[i]->x_min * cos(env->x_rot)) -
			(env->dot[i]->y_min * sin(env->x_rot)));
		env->dot[i]->y_min = ((env->dot[i]->x_min * sin(env->x_rot)) +
			(env->dot[i]->y_min * cos(env->x_rot)));
		env->dot[i]->x_min += env->x_move;
		env->dot[i]->y_min += env->y_move;
	}
}

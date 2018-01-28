/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:14:31 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/28 15:01:45 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		set_zoom(t_env *env, t_var *var)
{
	env->dot[var->i]->x_max = env->dot[var->i]->x +
		(env->dot[var->i]->x * env->zoom);
	env->dot[var->i]->y_max = env->dot[var->i]->y +
		(env->dot[var->i]->y * env->zoom);
}

static void		set_depth(t_env *env, t_var *var)
{
	env->dot[var->i]->z_max = env->dot[var->i]->z * env->depth;
}

static void		set_dec(t_env *env, t_var *var)
{
	env->dot[var->i]->x_min = (env->dec_width * env->dot[var->i]->x_max)
		- (env->dec_height * env->dot[var->i]->y_max);
	env->dot[var->i]->y_min = (env->dot[var->i]->z_max
			+ ((env->dec_width / 2) * env->dot[var->i]->x_max)
			+ ((env->dec_height / 2) * env->dot[var->i]->y_max));
}

static void		set_rot(t_env *env, t_var *var)
{
	env->dot[var->i]->x_min = ((env->dot[var->i]->x_min * cos(env->x_rot))
			- (env->dot[var->i]->y_min * sin(env->x_rot)));
	env->dot[var->i]->y_min = ((env->dot[var->i]->x_min * sin(env->x_rot))
			+ (env->dot[var->i]->y_min * cos(env->x_rot)));
}

void			set_var(t_env *env)
{
	t_var		var;

	var.i = 0;
	while (env->dot[var.i])
	{
		set_zoom(env, &var);
		set_depth(env, &var);
		set_dec(env, &var);
		set_rot(env, &var);
		env->dot[var.i]->x_min += env->x_move;
		env->dot[var.i]->y_min += env->y_move;
		var.i++;
	}
}

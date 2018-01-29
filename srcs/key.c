/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:41:12 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/29 15:16:11 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			reload_win(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	set_var(env);
	expose_func(env);
}

void			key_move(int keycode, t_env *env)
{
	if (keycode == ESCAPE)
	{
		mlx_clear_window(env->mlx, env->win);
		exit(0);
	}
	keycode == LOW_ROT ? env->x_rot -= 0.05 : env->x_rot;
	keycode == HIGH_ROT ? env->x_rot += 0.05 : env->x_rot;
	keycode == LEFT_ARROW ? env->x_move -= 20 : env->x_move;
	keycode == RIGHT_ARROW ? env->x_move += 20 : env->x_move;
	keycode == UP_ARROW ? env->y_move += 20 : env->y_move;
	keycode == DOWN_ARROW ? env->y_move -= 20 : env->y_move;
	keycode == ZOOM_PLUS ? env->zoom += 2 : env->zoom;
	keycode == ZOOM_MOINS ? env->zoom -= 2 : env->zoom;
	keycode == DEPTH_PLUS ? env->depth += 1 : env->depth;
	keycode == DEPTH_MOINS ? env->depth -= 1 : env->depth;
}

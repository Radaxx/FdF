/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:14:31 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/24 15:52:11 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		matrice_set(t_dot **tab, t_mat *mat, t_env *env)
{
	t_dot	*dot;

	dot = (t_dot *)ft_xmalloc(sizeof(t_dot));
	dot->x = mat->x;
	dot->y = mat->y;
	dot->z = env->map[mat->y][mat->x];
	tab[mat->i] = dot;
	mat->i++;
	mat->x++;
}

t_dot		**set_matrice(t_env *env)
{
	t_dot	**tab;
	t_mat	mat;

	mat.i = 0;
	mat.y = 0;
	tab = (t_dot **)ft_xmalloc(sizeof(t_dot) * env->width * env->height);
	while (mat.y < env->height)
	{
		mat.x = 0;
		while (mat.x < env->width)
			matrice_set(tab, &mat, env);
		mat.y++;
	}
	tab[mat.i] = NULL;
	return (tab);
}

void		set_var(t_env *env)
{
	int		i;

	i = 0;
	while (env->dot[i])
	{
		env->dot[i]->x_max = env->dot[i]->x + (env->dot[i]->x * env->zoom);
		env->dot[i]->y_max = env->dot[i]->y + (env->dot[i]->y * env->zoom);
		env->dot[i]->z_max = env->dot[i]->z * env->depth;
		env->dot[i]->x_min = (env->dec_width * env->dot[i]->x_max) - (env->dec_height * env->dot[i]->y_max);
		env->dot[i]->y_min = (env->dot[i]->z_max + ((env->dec_width / 2) * env->dot[i]->x_max) + ((env->dec_height / 2) * env->dot[i]->y_max));
		env->dot[i]->x_min = ((env->dot[i]->x_min * cos(env->x_rot)) - (env->dot[i]->y_min * sin(env->x_rot)));
		env->dot[i]->y_min = ((env->dot[i]->x_min * sin(env->x_rot)) + (env->dot[i]->y_min * cos(env->x_rot)));
		env->dot[i]->x_min += env->x_move;
		env->dot[i]->y_min += env->y_move;
		i++;
	}
}

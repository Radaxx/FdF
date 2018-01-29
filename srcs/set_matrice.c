/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_matrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:22:28 by aparabos          #+#    #+#             */
/*   Updated: 2018/01/29 13:09:50 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		matrice_set(t_dot **tab, t_mat *mat, t_env *env)
{
	t_dot *dot;

	dot = (t_dot *)ft_xmalloc(sizeof(t_dot));
	dot->x = mat->x;
	dot->y = mat->y;
	dot->z = env->map[mat->y][mat->x];
	tab[mat->i] = dot;
	mat->i++;
	mat->x++;
}

t_dot			**set_matrice(t_env *env)
{
	t_dot		**tab;
	t_mat		mat;

	mat.i = 0;
	mat.y = 0;
	tab = (t_dot **)ft_xmalloc(sizeof(t_dot *) * env->width * env->height);
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
